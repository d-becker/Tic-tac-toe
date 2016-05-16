#include "GameFlow.hpp"

namespace ttt {

GameFlow::GameFlow()
  : m_game(nullptr)
{
}

GameFlow::~GameFlow()
{
}

void GameFlow::newGame()
{
  if (m_game)
    m_game->clearState();
}

void GameFlow::newGame(std::shared_ptr<Game> game)
{
  m_game = game;
  if (m_game)
    m_game->clearState();
}

bool GameFlow::takeMove(const Vec2& pos)
{
  if (!m_game)
    return false;
  
  bool success = m_game->takeMove(pos);
  // TODO!!!
}

} // namespace ttt
