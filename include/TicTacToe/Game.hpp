#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <vector>

#include "TicTacToe/Board.hpp"

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

  /**
   * Returns \c true if the game is over.
   *
   * \return \c true if the game is over; \c false otherwise.
   */
  virtual bool isGameOver() const = 0;

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
   * Updates the state that stores information about the state of the current
   * game (players who have a winning sequence and where these are). This method
   * checks the whole board, so if a winning position is expected, it can be
   * better to use the method which takes the position.
   *
   * If there are no winning sequences, the fields storing the id numbers of
   * the winning players and the winning positions are set to an emtpy vector.
   *
   * Note: the value that is returned by the method \c isGameOver is never
   * modified by this method as the conditions for when the game is over can
   * depend on the rules of the actual game.
   */
  void updateWinnerState();

  /**
   * Checks the given position and if that is a place where the game is won,
   * the state that stores information about the state of the game is updated.
   * Otherwise the stored values are not modified.
   * 
   * Note: the value that is returned by the method \c isGameOver is never
   * modified by this method as the conditions for when the game is over can
   * depend on the rules of the actual game.   *
   * \param pos The position to check.
   */
  void updateWinnerState(const Vec2& pos);

  /**
   * Checks the state of the game with regards to winner sequences.
   *
   * \param winners An output parameter that is set to contain the id numbers of
   *        the players that have a winnig sequence.
   * \param winner_positions An output parameter that will contain
   *        the positions of the winning sequences.
   */
  virtual void checkWinnerState(std::vector<int>& winners,
				std::vector<
				  std::vector<Vec2>
				           >& winners_positions) const;

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
   * Returns a vector containing the id numbers of the winners. Note that if the
   * game is not over yet, this is not the final list of the winners as more
   * winners can appear.
   *
   * \return A vector containing the id numbers of the winners.
   */
  virtual const std::vector<int>& getWinners() const;

  /**
   * Returns a vector containing vectors that contain the positions of the
   * stones in the individual winning sequences. If there is no winning
   * sequence, an empty vector is returned.
   *
   * \return A vector containing vectors that contain the positions of the
   *         stones in the individual winning sequences.
   */
  virtual const std::vector< std::vector<Vec2> >& getWinnersPositions() const;

  /**
   * Clears the state of the game so that a new game can start. All subclasses
   * should override this method if they have additional state in addition to
   * the state in the base class. The overridden methods should always call the
   * \c clearState method of the parent class.
   */
  virtual void clearState() = 0;
  
  /**
   * Returns a polymorphic copy of this \c Game object.
   *
   * \return A polymorphic copy of this \c Game object.
   */
  virtual std::shared_ptr<Game> clone() const = 0;
protected:
  const int m_length_to_win;
  const int m_num_of_players;

  std::vector<int>  m_winners;
  std::vector< std::vector<Vec2> > m_winners_positions;
private:
  const std::shared_ptr<Board> m_board;
  int m_current_player; // From 1 to m_num_of_players.

  int m_moves_taken;
};

} // namespace ttt.
#endif // GAME_HPP
