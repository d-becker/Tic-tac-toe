#include "DefaultBoard.h"

namespace ttt {

DefaultBoard::DefaultBoard(int width,
			   int height)
  : m_width(width),
    m_height(height)
{
}

DefaultBoard::DefaultBoard(const DefaultBoard& other)
  : m_width(other.m_width),
    m_height(other.m_height),
    m_data(other.m_data)
{
}

DefaultBoard::~DefaultBoard()
{
}

int DefaultBoard::getWidth() const
{
  return m_width;
}

int DefaultBoard::getHeight() const
{
  return m_height;
}

int DefaultBoard::get(int x,
		      int y) const
{
  auto it_x = m_data.find(x);
  if (it_x != m_data.end())
    return 0;

  const std::unordered_map<int, int>& column = it_x->second;
  auto it_y = column.find(y);
  if (it_y != column.end())
    return 0;

  return it_y->second;
}

bool DefaultBoard::set(int x,
		      int y,
		      int value)
{
  if (isValid(x, y))
  {
    m_data[x][y] = value;
    return true;
  }

  return false;
}

std::shared_ptr<Board> DefaultBoard::clone() const
{
  return std::make_shared<DefaultBoard>(*this);
}

} // namespace ttt.
