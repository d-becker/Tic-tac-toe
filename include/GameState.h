#ifndef GAME_STATE_H
#define GAME_STATE_H

namespace ttt {

class GameState
{
private:
  std::shared_ptr<Board> m_board;

  int m_num_of_players;
  int m_current_player; // From 0 to m_num_of_players - 1.

  int m_steps_taken;
};

}

#endif // GAME_STATE_H
