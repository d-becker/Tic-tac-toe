#include "GameFlow.hpp"

namespace ttt {

GameFlow::GameFlow(std::initializer_list<
		   std::pair< const std::string, std::shared_ptr<GameFactory> >
		   > game_factories)
  : m_game(nullptr),
    m_game_playing(false),
    m_game_factories(game_factories)
{
}

GameFlow::~GameFlow()
{
}

bool GameFlow::newGame()
{
  if (m_game)
  {
    m_game->clearState();
    m_game_playing = true;
    return true;
  }

  return false;
}

bool GameFlow::newGame(std::string game_factory_name,
		       int width,
		       int height,
		       int num_of_players,
		       int length_to_win)
{
  std::shared_ptr<GameFactory> factory = get_factory_by_name(game_factory_name);
  if (!factory)
    return false;

  std::shared_ptr<Game> game = factory->create(width, height, num_of_players,
					       length_to_win);
  if (!game)
    return false;

  m_game = game;
  m_game_playing = true;
  return true;
}

bool GameFlow::takeMove(const Vec2& pos)
{
  if (!m_game_playing || !m_game)
    return false;
  
  bool success = m_game->takeMove(pos);
  if (success)
  {
    if (m_game->isGameOver())
      m_game_playing = false;
  }

  return success;
}

std::shared_ptr<GameFactory>
GameFlow::bindGameFactory(std::string name,
		          std::shared_ptr<GameFactory> game_factory)
{
  std::shared_ptr<GameFactory> old_factory = get_factory_by_name(name);
  m_game_factories[name] = game_factory;
  return old_factory;
}

std::shared_ptr<GameFactory> GameFlow::unbindGameFactory(std::string name)
{
  std::shared_ptr<GameFactory> old_factory = get_factory_by_name(name);
  m_game_factories.erase(name);
  return old_factory;
}

bool GameFlow::isGamePlaying() const
{
  return m_game_playing;
}

const std::vector<int>& GameFlow::getWinners() const
{
  static const std::vector<int> empty{};
  
  if (!m_game_playing && m_game)
    return m_game->getWinners();
  else
    return empty;
}

const std::vector< std::vector<Vec2> >& GameFlow::getWinnersPositions() const
{
  static const std::vector< std::vector<Vec2> > empty{};
  
  if (!m_game_playing && m_game)
    return m_game->getWinnersPositions();
  else
    return empty;
}

// Private
std::shared_ptr<GameFactory> GameFlow::get_factory_by_name(std::string name)
{
  auto it = m_game_factories.find(name);
  std::shared_ptr<GameFactory> res = it != m_game_factories.end() ?
                                            it->second : nullptr;
  return res;
}

} // namespace ttt
