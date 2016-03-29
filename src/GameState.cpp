#include "GameState.h"

namespace ttt {

GameState::GameState(std::shared_ptr<Board> board,
		     int num_of_players)
  : m_board(board),
    m_num_of_players(num_of_players),
    m_current_player(0),
    m_steps_taken(0)
{
}

GameState::GameState(const GameState& other)
  : m_board(other.m_board->clone()),
    m_num_of_players(other.m_num_of_players),
    m_current_player(other.m_current_player),
    m_steps_taken(other.m_steps_taken)
{
}

GameState::GameState(GameState&& other)
  : m_board(other.m_board),
    m_num_of_players(other.m_num_of_players),
    m_current_player(other.m_current_player),
    m_steps_taken(other.m_steps_taken)
{
}

GameState::~GameState()
{
}

std::shared_ptr<const Board> GameState::getBoard() const
{
  return m_board;
}

int GameState::getNumberOfPlayers() const
{
  return m_num_of_players;
}

int GameState::getCurrentPlayer() const
{
  return m_current_player;
}

int GameState::getStepsTaken() const
{
  return m_steps_taken;
}

} // namespace ttt.
