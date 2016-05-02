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
  // TODO.
}

void GameFlow::newGame(std::shared_ptr<Game> game)
{
  // TODO.
}

bool GameFlow::takeMove(const Vec2& pos)
{
  bool success = m_game->takeMove(pos);
  // TODO!!!
}

} // namespace ttt
