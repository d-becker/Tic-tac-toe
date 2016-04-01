#include "TraditionalGame.h"

namespace ttt {

TraditionalGame::TraditionalGame(std::shared_ptr<Board> board,
				 int num_of_players)
  : Game(board, num_of_players)
{
}

TraditionalGame::TraditionalGame(const TraditionalGame& other)
  : Game(other)
{
}

TraditionalGame::TraditionalGame(TraditionalGame&& other)
  : Game(other)
{
}

TraditionalGame::~TraditionalGame()
{
}

bool TraditionalGame::isLegal(const Vec2& pos,
			      int player) const
{
  return getBoard()->get(pos) == 0;
}

bool TraditionalGame::isGameOver(int& winner,
				 std::vector<Vec2>& winner_positions) const
{
  // TODO.
}

std::shared_ptr<Game> TraditionalGame::clone() const
{
  return std::make_shared<TraditionalGame>(*this);
}

} // namespace ttt.
