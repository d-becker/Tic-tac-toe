#ifndef TRADITIONAL_GAME_HPP
#define TRADITIONAL_GAME_HPP

#include "TicTacToe/Game.hpp"
#include "TicTacToe/Vec2.hpp"

namespace ttt {

class TraditionalGame : public Game
{
public:
  TraditionalGame(std::shared_ptr<Board> board,
		  int num_of_players,
		  int length_to_win);
  TraditionalGame(const TraditionalGame& other);
  TraditionalGame(TraditionalGame&& other);
  virtual ~TraditionalGame();

  virtual bool isGameOver() const override;
  virtual bool isLegal(const Vec2& pos,
		       int player) const override;

  virtual std::shared_ptr<Game> clone() const override;

  virtual bool isGameWonAt(const Vec2& pos,
			   int& winner,
			   std::vector<Vec2>& winner_positions) const override;

  virtual void clearState() override;
};

} // namespace ttt.

#endif // TRADITIONAL_GAME_HPP
