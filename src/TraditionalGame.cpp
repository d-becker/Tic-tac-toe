#include "TraditionalGame.h"

#include <algorithm>


namespace /* anonymous */ {

bool checkGameWonInDirection(const ttt::Vec2& pos,
			     int& winner,
			     std::vector<ttt::Vec2>& winner_positions,
			     const ttt::Vec2& dir,
			     std::shared_ptr<const ttt::Board> board,
			     unsigned int length_to_win)
{
  using namespace ttt;
  
  winner = board->get(pos);
  if(winner == 0)
    return false;

  winner_positions.clear();
  winner_positions.push_back(pos);
  
  Vec2 forward_pos = pos + dir;
  for (; board->get(forward_pos) == winner; forward_pos += dir)
  {
    winner_positions.push_back(forward_pos);
  }

  std::reverse(winner_positions.begin(), winner_positions.end());
  
  Vec2 backward_pos = pos - dir;
  for (; board->get(backward_pos) == winner; backward_pos -= dir)
  {
    winner_positions.push_back(backward_pos);
  }

  return winner_positions.size() >= length_to_win;
}

} // anonymous namespace

namespace ttt {

TraditionalGame::TraditionalGame(std::shared_ptr<Board> board,
				 int num_of_players,
				 int length_to_win)
  : Game(board, num_of_players, length_to_win)
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

bool TraditionalGame::isGameOver() const
{
  // Someone has a winning sequence
  if (!m_winners.empty())
    return true;

  // The board is full
  std::shared_ptr<const Board> board = getBoard();
  if (getMovesTaken() >= board->getWidth() * board->getHeight())
    return true;

  // Game is not over
  return false;
}

bool TraditionalGame::isLegal(const Vec2& pos,
			      int player) const
{
  return getBoard()->get(pos) == 0;
}

std::shared_ptr<Game> TraditionalGame::clone() const
{
  return std::make_shared<TraditionalGame>(*this);
}

bool TraditionalGame::isGameWonAt(const Vec2& pos,
				  int& winner,
				  std::vector<Vec2>& winner_positions) const
{
  static const std::vector<Vec2> directions {Vec2(1, 0), Vec2(0, 1),
                                             Vec2(1, 1), Vec2(1, -1)};
  std::shared_ptr<const Board> board = getBoard();
  
  for (const Vec2& dir : directions)
  {
    bool won = checkGameWonInDirection(pos, winner, winner_positions,
				       dir, board, m_length_to_win);
    if (won)
      return true;
  }

  return false;
}

} // namespace ttt.
