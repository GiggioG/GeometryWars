#include "Game.h"

Player Game::m_player = Player();

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
	m_enemy.init();
	m_enemy.spawn();
}

void Game::destroy()
{

}

void Game::run()
{
	m_board.update();
	m_player.update();
	m_enemy.update();

	m_board.draw();
	m_player.draw();
	m_enemy.draw();
}

float2 Game::getCoords()
{
	return { m_player.d.drect.x, m_player.d.drect.y };
}
