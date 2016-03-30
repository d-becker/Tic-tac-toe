#include <iostream>
#include <memory>

#include "Board.h"
#include "DefaultBoard.h"
#include "Vec2.h"

using namespace std;
using namespace ttt;

void printBoard(std::ostream& out, std::shared_ptr<Board> board)
{
  for (int x = 0; x < board->getHeight(); ++x)
  {
    for (int y = 0; y < board->getWidth(); ++y)
    {
      out << board->get(x, y) << '\t';
    }

    out << '\n';
  }
}

int main() {
  cout << "Hello World!\n";
  shared_ptr<Board> b = make_shared<DefaultBoard>(5, 5);
  b->set(0, 0, 5);
  b->set(0, 3, -7);
  b->set(10, 2, -4);
  printBoard(cout, b);
  
  return 0;
}
