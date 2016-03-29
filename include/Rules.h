#ifndef RULES_H
#define RULES_H

#include "GameState.h"

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
   * \param game_state The current state of the game.
   * \param pos The position of the proposed move.
   * \param The player that is to take that move.
   * 
   * \return \c true if the proposed move is legal; \c false otherwise. 
   */
  virtual bool isLegal(const GameState& game_state,
		       const Vec2& pos,
		       int player) const = 0;

  /**
   * Checks whether the game is over accordig to the rules of the game.
   *
   * \param game_state The current state of the game.
   *
   * \return \c true if the game is over; \c false otherwise.
   */
  virtual bool isGameOver(const GameState& game_state) const = 0;
};

#endif // RULES_H
