#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	m_board.init();
	m_player.init();
}

void Game::destroy()
{

}

void Game::run()
{
	m_board.update();
	m_player.update();

	m_board.draw();
	m_player.draw();
}