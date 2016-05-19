#ifndef TRADITIONAL_GAME_FACTORY_HPP
#define TRADITIONAL_GAME_FACTORY_HPP

#include "TicTacToe/GameFactory.hpp"

#include "TicTacToe/DefaultBoard.hpp"
#include "TicTacToe/TraditionalGame.hpp"

namespace ttt {

/**
 * This implementation of the \c GameFactory interface creates
 * \c TraditionalGame instances.
 */
class TraditionalGameFactory : public GameFactory
{
public:
  virtual std::shared_ptr<Game> create(int width,
				       int height,
				       int num_of_players,
				       int length_to_win) override
  {
    using namespace std;
    
    // Creating the board
    shared_ptr<Board> board = make_shared<DefaultBoard>(width, height);
    
    // Creating the TraditionalGame instance
    shared_ptr<Game> game = make_shared<TraditionalGame>(board,
							 num_of_players,
							 length_to_win);
    return game;
  }
};

} // namespace ttt

#endif // TRADITIONAL_GAME_FACTORY_HPP
