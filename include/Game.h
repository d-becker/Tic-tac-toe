#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "Board.h"

namespace ttt {

/**
 * A interface that represents the game state and rules.
 */
class Game
{
public:
  /**
   * Constructs a new \c Game object.
   *
   * \param board A smart pointer to the game board.
   * \param num_of_players The number of players this game has.
   */
  Game(std::shared_ptr<Board> board,
       int num_of_players,
       int length_to_win);

  Game(const Game& other);
  Game(Game&& other);
  virtual ~Game();
  
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
  int getMovesTaken() const;

  bool isGameOver() const;

  /**
   * Takes the specified move by the current player if it is possible.
   *
   * \param pos The position of the move.
   *
   * \return \c true if the move has been taken; \c false if it was not possible.
   */
  virtual bool takeMove(const Vec2& pos);
  
  /**
   * Checks whether a proposed move is legal according to the rules of the game.
   *
   * \param pos The position of the proposed move.
   * \param The player that is to take that move.
   * 
   * \return \c true if the proposed move is legal; \c false otherwise. 
   */
  virtual bool isLegal(const Vec2& pos,
		       int player) const = 0;

  /**
   * Checks whether the game is over accordig to the rules of the game.
   *
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
  virtual bool checkGameOver(int& winner,
			     std::vector<Vec2>& winner_positions) const;

  /**
   * Checks whether the stone at the given cell is part of a winning line.
   *
   * \param pos The position of the cell to check.
   *
   * \param winner An output parameter that is set to the id number of
   *        the winning player if the game has been won. If the game is not over
   *        or ended in a draw, it is undefined if the value is modified.
   * \param winner_positions An output parameter that will contain
   *        the positions of the winning stones if the game has been won.
   *        If the game is not over or ended in a draw,
   *        it is undefined if the value is modified.
   *
   * \return \c true if the stone at the given cell is part of a winning line;
   *         \c false otherwise.
   */
  virtual bool isGameWonAt(const Vec2& pos,
			   int& winner,
			   std::vector<Vec2>& winner_positions) const = 0;
  
  /**
   * Returns a polymorphic copy of this \c Game object.
   *
   * \return A polymorphic copy of this \c Game object.
   */
  virtual std::shared_ptr<Game> clone() const = 0;
protected:
  const int m_length_to_win;
  const int m_num_of_players;
private:
  const std::shared_ptr<Board> m_board;
  int m_current_player; // From 0 to m_num_of_players - 1.

  int m_moves_taken;
  bool m_game_over;
};

} // namespace ttt.
#endif // GAME_H
