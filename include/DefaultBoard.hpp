#ifndef DEFAULT_BOARD_HPP
#define DEFAULT_BOARD_HPP

#include <unordered_map>

#include "Board.hpp"

namespace ttt {

class DefaultBoard : public Board
{
public:
  DefaultBoard(int width,
	       int height);
  DefaultBoard(const DefaultBoard& other);
  virtual ~DefaultBoard();

  virtual int getWidth() const override;
  virtual int getHeight() const override;

  using Board::get;
  virtual int get(int x,
		  int y) const override;

  using Board::set;
  virtual bool set(int x,
		   int y,
		   int value) override;

  virtual void clear() override;
  
  virtual std::shared_ptr<Board> clone() const override;

private:
  const int m_width;
  const int m_height;

  std::unordered_map<int, std::unordered_map<int, int>> m_data;
};

} // namespace ttt.

#endif // DEFAULT_BOARD_HPP
