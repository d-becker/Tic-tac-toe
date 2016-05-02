#ifndef GAME_FLOW_HPP
#define GAME_FLOW_HPP

#include <memory>

#include "Game.hpp"

namesapce ttt {

class GameFlow
{
public:
  GameFlow();
  virtual ~GameFlow();

  virtual void newGame(); // TODO
private:
  std::shared_ptr<Game> m_game;
};
  
} // namespace ttt

#endif // GAME_FLOW_HPP
