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
    m_height(other.m_height)
{
  // TODO.
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
  // TODO.
}

bool DefaultBoard::set(int x,
		      int y,
		      int value)
{
  // TODO.
}

std::shared_ptr<Board> DefaultBoard::clone() const
{
  return std::make_shared<DefaultBoard>(*this);
}

} // namespace ttt.
