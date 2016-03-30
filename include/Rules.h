#ifndef RULES_H
#define RULES_H

#include <vector>

class Game;
class Vec2;

/**
 * A interface whose implementations represent the set of rules
 * for a particular type of the game.
 */
class Rules
{
 public:
  virtual ~Rules() {}
  
  /**
   * Checks whether a proposed move is legal according to the rules of the game.
   *
   * \param game The current game object.
   * \param pos The position of the proposed move.
   * \param The player that is to take that move.
   * 
   * \return \c true if the proposed move is legal; \c false otherwise. 
   */
  virtual bool isLegal(const Game& game,
		       const Vec2& pos,
		       int player) const = 0;

  /**
   * Checks whether the game is over accordig to the rules of the game.
   *
   * \param game The current game object.
   * \param winner An output parameter that is set to the id number of
   *        the winning player if the game has been won. If the game is not over
   *        or ended in a draw, it is undefined if the value is modified.
   * \param winner_positions An output parameter that will contain
   *        the positions of the winning stones if the game has been won.
   *        If the game is not over or ended in a draw,
   *        it is undefined if the value is modified.
   *
   * \return \c true if the game is over; \c false otherwise.
   */
  virtual bool isGameOver(const Game& game,
			  int& winner,
			  std::vector<Vec2>& winner_positions) const = 0;
};

#endif // RULES_H
