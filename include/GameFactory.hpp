#ifndef GAME_FACTORY_HPP
#define GAME_FACTORY_HPP

#include <memory>

#include "Game.hpp"

namespace ttt {

/**
 * This interface can be used to create polymorphic \c Game instances.
 * Instances of implementors of this interface can be used by \c GameFlow
 * or other game managers to choose the type of the game.
 */
class GameFactory
{
public:
  /**
   * Returns a (smart) pointer to a new \c Game object with the given
   * parameters. The dynamic type of the \c Game object depends on this
   * \c GameFactory instance.
   *
   * \param width The width of the \c Board of the new \c Game object.
   * \param height The height of the \c Board of the new \c Game object.
   * \param num_of_players The number of players that play the new \c Game.
   * \param length_to_win The length of a winning sequence.
   */
  virtual std::shared_ptr<Game> create(int width,
				       int height,
				       int num_of_players,
				       int length_to_win) = 0;
};

} // namespace ttt

#endif // GAME_FACTORY_HPP
