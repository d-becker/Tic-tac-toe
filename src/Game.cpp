#include "Game.h"

namespace ttt {

Game::Game(std::shared_ptr<Board> board,
	   int num_of_players,
	   int length_to_win)
  : m_length_to_win(length_to_win),
    m_num_of_players(num_of_players),
    m_game_over(false),
    m_winner(0),
    m_winner_positions(),
    m_board(board),
    m_current_player(0),
    m_moves_taken(0)
{
}

Game::Game(const Game& other)
  : m_length_to_win(other.m_length_to_win),
    m_num_of_players(other.m_num_of_players),
    m_game_over(other.m_game_over),
    m_winner(other.m_winner),
    m_winner_positions(other.m_winner_positions),
    m_board(other.m_board->clone()),
    m_current_player(other.m_current_player),
    m_moves_taken(other.m_moves_taken)
{
}

Game::Game(Game&& other)
  : m_length_to_win(other.m_length_to_win),
    m_num_of_players(other.m_num_of_players),
    m_game_over(other.m_game_over),
    m_winner(other.m_winner),
    m_winner_positions(other.m_winner_positions),
    m_board(other.m_board),
    m_current_player(other.m_current_player),
    m_moves_taken(other.m_moves_taken)    
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

int Game::getMovesTaken() const
{
  return m_moves_taken;
}

bool Game::isGameOver() const
{
  return m_game_over;
}

bool Game::takeMove(const Vec2& pos)
{
  if (!isLegal(pos, m_current_player) || !m_board->set(pos, m_current_player))
      return false;

  ++m_moves_taken;
  m_current_player = m_moves_taken % m_num_of_players;

  return true;
}

void Game::updateWinnerState()
{
  for (int i = 0; i < m_board->getWidth(); ++i)
  {
    for (int j = 0; j < m_board->getHeight(); ++j)
    {
      if (isGameWonAt(Vec2(i, j), m_winner, m_winner_positions))
      {
	m_game_over = true;
	return;
      }
    }
  }

  m_game_over = false;
  m_winner = 0;
  m_winner_positions.clear();
}

void Game::updateWinnerState(const Vec2& pos)
{
  int winner;
  std::vector<Vec2> winner_positions;
  if (isGameWonAt(pos, winner, winner_positions))
  {
    m_game_over = true;
    m_winner = winner;
    m_winner_positions = winner_positions;
  }

}

// This implementation is not optimal, it can be better if the underlying
// data structure of the board is known.
bool Game::checkGameOver(int& winner,
			 std::vector<Vec2>& winner_positions) const
{
  std::shared_ptr<const Board> board = getBoard();
  int width = board->getWidth();
  int height = board->getHeight();
  
  if (m_moves_taken >= width * height)
  {
    winner = 0;
    return true;
  }

  for (int i = 0; i < width; ++i)
  {
    for (int j = 0; j < height; ++j)
    {
      bool won = isGameWonAt(Vec2(i, j), winner, winner_positions);
      if (won)
      {
	return true;
      }
    }
  }

  return false;
}

int Game::getWinner() const
{
  return m_winner;
}

std::vector<Vec2> Game::getWinnerPositions() const
{
  return m_winner_positions;
}

} // namespace ttt.
