#ifndef GAME_FLOW_HPP
#define GAME_FLOW_HPP

#include <memory>

#include "Game.hpp"
#include "Vec2.hpp"

namespace ttt {

class GameFlow
{
public:
  GameFlow();
  virtual ~GameFlow();

  /**
   * Starts a new game with the current settings. This method calls the method
   * \c clearState on the current game.
   */
  void newGame();

  /**
   * Starts a new game with the given \c Game object. This method calls the
   * method \c clearState on the new \c Game object.
   *
   * \param game The game object to use in the new game.
   */
  void newGame(std::shared_ptr<Game> game);

  /**
   * Takes the specified move by the current player if it is possible.
   *
   * \param pos The position of the move.
   *
   * \return \c true if the move has been taken;
   *         \c false if it was not possible.
   */
  bool takeMove(const Vec2& pos);
private:
  std::shared_ptr<Game> m_game;
};
  
} // namespace ttt

#endif // GAME_FLOW_HPP
