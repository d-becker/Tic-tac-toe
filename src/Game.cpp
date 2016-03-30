#include "Game.h"

namespace ttt {

Game::Game(std::shared_ptr<Board> board,
	   int num_of_players)
  : m_board(board),
    m_num_of_players(num_of_players),
    m_current_player(0),
    m_steps_taken(0)
{
}

Game::Game(const Game& other)
  : m_board(other.m_board->clone()),
    m_num_of_players(other.m_num_of_players),
    m_current_player(other.m_current_player),
    m_steps_taken(other.m_steps_taken)
{
}

Game::Game(Game&& other)
  : m_board(other.m_board),
    m_num_of_players(other.m_num_of_players),
    m_current_player(other.m_current_player),
    m_steps_taken(other.m_steps_taken)
{
}

Game::~Game()
{
}

std::shared_ptr<const Board> Game::getBoard() const
{
  return m_board;
}

int Game::getNumberOfPlayers() const
{
  return m_num_of_players;
}

int Game::getCurrentPlayer() const
{
  return m_current_player;
}

int Game::getStepsTaken() const
{
  return m_steps_taken;
}

} // namespace ttt.