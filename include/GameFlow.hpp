#ifndef GAME_FLOW_HPP
#define GAME_FLOW_HPP

#include <initializer_list>
#include <memory>
#include <unordered_map>
#include <utility> // For std::pair

#include "Game.hpp"
#include "GameFactory.hpp"
#include "Vec2.hpp"

namespace ttt {

class GameFlow
{
public:
  GameFlow(std::initializer_list<
	   std::pair< const std::string, std::shared_ptr<GameFactory> >
	   > game_factories);
  virtual ~GameFlow();

  /**
   * Starts a new game with the current settings. This method calls the method
   * \c clearState on the current game.
   * If there is no current game, no new game is created.
   *
   * \return \c true if a new game was started; \c false otherwise.
   */
  bool newGame();

  /**
   * Starts a new game with the given parameters if it is possible.
   * If it is not possible, for example because the specified \c GameFactory
   * does not exist or it returned a null game, no new game is started.
   *
   * \param game_factory_name The name of the game factory to use to
   *        generate the game.
   * \param width The width of the board of the new game.
   * \param height The height of the board of the new game.
   * \param num_of_players The number of players that will play the new game.
   * \param length_to_win The length of a winning sequence.
   */
  bool newGame(std::string game_factory_name,
	       int width,
	       int height,
	       int num_of_players,
	       int length_to_win);

  /**
   * Takes the specified move by the current player if it is possible.
   *
   * \param pos The position of the move.
   *
   * \return \c true if the move has been taken;
   *         \c false if it was not possible.
   */
  bool takeMove(const Vec2& pos);

  /**
   * Adds the specified name - \c GameFactory binding to this \c GameFlow
   * object. If another \c GameFactory is already bound to \a name, the old
   * binding is deleted and the new one made.
   *
   * \param name The name to which the \c GameFactory is bound.
   * \param game_factory The \c GameFactory object
   *        that will be bound to \a name.
   *
   * \return The \c GameFactory object that was bound to \a name if one existed;
   *         \c nullptr otherwise.
   */
  std::shared_ptr<GameFactory> bindGameFactory(
				    std::string name,
				    std::shared_ptr<GameFactory> game_factory);

  /**
   * Removes the binding with the name \a name if it exists.
   *
   * \param name The name of the binding.
   *
   * \return The \c GameFactory object that was bound to \a name if one existed;
   *         \c nullptr otherwise.
   */
  std::shared_ptr<GameFactory> unbindGameFactory(std::string name);

  /**
   * Returns whether a game is being played now.
   *
   * \return \c true if a game is being played now; \c false otherwise.
   */
  bool isGamePlaying() const;

  /**
   * Returns a vector containing the id numbers of the winners if the game is
   * over or an empty vector if the game is still being played.
   *
   * \return A vector containing the id numbers of the winners if the game is
   *         over or an empty vector if the game is still being played.
   */
  const std::vector<int>& getWinners() const;
  
  /**
   * Returns a vector containing vectors that contain the positions of the
   * stones in the individual winning sequences if the game is over. If the game
   * is still being played, an empty vector is returned.
   *
   * \return A vector containing vectors that contain the positions of the
   *         stones in the individual winning sequences if the game is over
   *         or an empty vector if the game is still being played.
   */
  const std::vector< std::vector<Vec2> >& getWinnersPositions() const;
private:
  // Returns a smart pointer to the game factory that is bound to the
  // given name if one exists; nullptr otherwise.
  std::shared_ptr<GameFactory> get_factory_by_name(std::string name);
  
  std::shared_ptr<Game> m_game;
  bool m_game_playing;
  std::unordered_map< std::string,
		      std::shared_ptr<GameFactory> > m_game_factories;
};
  
} // namespace ttt

#endif // GAME_FLOW_HPP
