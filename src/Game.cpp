#include "Game.h"

Player Game::m_player = Player();
list<Bullet> Game::m_bullets = list<Bullet>();

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
	Bullet::model.init();
	m_enemy.spawn();
}

void Game::destroy()
{

}

void Game::run()
{
	m_board.update();
	m_player.update();
	for (list<Bullet>::iterator it = m_bullets.begin(); it != m_bullets.end();) {
		it->update();
		if (it->out_of_bounds) {
			list<Bullet>::iterator it2 = it;
			++it;
			m_bullets.erase(it2);
		}else {
			++it;
		}
	}
	m_enemy.update();

	m_board.draw();
	m_player.draw();
	for (list<Bullet>::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it) {
		it->draw();
	}
	m_enemy.draw();
}

float2 Game::getCoords()
{
	return { m_player.d.drect.x, m_player.d.drect.y };
}
