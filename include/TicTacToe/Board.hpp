#ifndef BOARD_HPP
#define BOARD_HPP

#include <memory>

#include "TicTacToe/Vec2.hpp"

namespace ttt {

/**
 * An interface for a low-level class that represents a game board.
 * The values are <tt>int</tt>s, where 0 means empty and other numbers are
 * the identifiers of the players.
 *
 * The coordinate system is zero-based, with the cell with coordinates (0, 0)
 * being at the top left corner. The positive x-axis grows rightwards
 * and the positive y-axis grows downwards.
 */
class Board
{
public:
  virtual ~Board() {}

  /**
   * Returns the number columns on the board.
   *
   * \return The number columns on the board.
   */
  virtual int getWidth() const = 0;

  /**
   * Returns the number of rows on the board.
   *
   * \return The number of rows on the board.
   */
  virtual int getHeight() const = 0;

  /**
   * Returns the value at the cell with coordinates \a x, \a y.
   *
   * \param x The x coordinate of the cell.
   * \param y The y coordinate of the cell.
   * 
   * \return The value at the point \a x, \a y.
   */
  virtual int get(int x,
		  int y) const = 0;

  /**
   * The same as \c get(vec.x, vec.y).
   */
  virtual bool get(const Vec2& vec) const
  {
    return get(vec.x, vec.y);
  }
  
  /**
   * Returns \c true if the given cell exists.
   *
   * \return \c true if the given cell exists; \c false otherwise.
   */
  bool isValid(int x, int y) const
  {
    return x >= 0 && x < getWidth() && y >= 0 && y < getHeight();
  }

  /**
   * The same as \c isValid(vec.x, vec.y).
   */
  bool isValid(const Vec2& vec) const
  {
    return isValid(vec.x, vec.y);
  }

  /**
   * Sets the value of the cell with coordinates \a x, \a y to \a value.
   *
   * \param x The x coordinate of the cell.
   * \param y The y coordinate of the cell.
   * \param value The new value of the cell.
   *
   * \return \c true if the given cell was set;
   *         \c false if the given cell was not set (because it does not exist).
   */
  virtual bool set(int x,
		   int y,
		   int value) = 0;

  /**
   * The same as \c set(vec.x, vec.y, value).
   */
  virtual bool set(const Vec2& vec,
		   int value)
  {
    return set(vec.x, vec.y, value);
  }

  /**
   * Clears the board, that is, sets all cells to 0.
   */
  virtual void clear() = 0;

  /**
   * Returns a polymorphic copy of this \c Board object.
   *
   * \return A polymorphic copy of this \c Board object.
   */
  virtual std::shared_ptr<Board> clone() const = 0;

};

} // namespace ttt.

#endif // BOARD_HPP
