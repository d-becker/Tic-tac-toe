#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>

#include "Board.h"

namespace ttt {

/**
 * A class that stores the game state.
 */
class GameState
{
public:
  /**
   * Constructs a new \c GameState object.
   *
   * \param board A smart pointer to the game board.
   * \param num_of_players The number of players this game has.
   */
  GameState(std::shared_ptr<Board> board,
	    int num_of_players);

  GameState(const GameState& other);
  GameState(GameState&& other);
  virtual ~GameState();
  
  /**
   * Returns a const (smart) pointer to the game board.
   *
   * \return A const (smart) pointer to the game board.
   */
  std::shared_ptr<const Board> getBoard() const;

  /**
   * Returns the number of players.
   *
   * \return The number of players.
   */
  int getNumberOfPlayers() const;

  /**
   * Returns the number of the current player
   * (from 0 to getNumberOfPlayers - 1).
   *
   * \return The number of the current player
   *         (from 0 to getNumberOfPlayers - 1).
   */
  int getCurrentPlayer() const;

  /**
   * Returns the number of steps that have been taken in this game.
   *
   * \return The number of steps that have been taken in this game.
   */
  int getStepsTaken() const;
  
private:
  const std::shared_ptr<Board> m_board;

  const int m_num_of_players;
  int m_current_player; // From 0 to m_num_of_players - 1.

  int m_steps_taken;
};

} // namespace ttt.

#endif // GAME_STATE_H
