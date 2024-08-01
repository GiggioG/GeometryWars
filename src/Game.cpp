#include "Game.h"
#include "InputManager.h"
#include "Chaser.h"
#include "Asteroid.h"

Player Game::m_player = Player();
list<Bullet> Game::m_bullets = list<Bullet>();
list<Enemy> Game::m_enemies = list<Enemy>();

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
	Enemy::model.init();
	Bullet::model.init();
	//m_enemy.spawn();
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
		if (it->toDelete) {
			list<Bullet>::iterator it2 = it;
			++it;
			m_bullets.erase(it2);
		}else {
			++it;
		}
	}
	for (list<Enemy>::iterator it = m_enemies.begin(); it != m_enemies.end();) {
		it->update();
		if (it->toDelete) {
			list<Enemy>::iterator it2 = it;
			++it;
			m_enemies.erase(it2);
		}
		else {
			++it;
		}
	}
	
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_A)) {
		//cout << "a" << endl;
		Chaser temp_c;
		temp_c.spawn();
		m_enemies.push_back(temp_c);
	}
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_B)) {
		//cout << "b" << endl;

		Asteroid temp_a;
		temp_a.spawn();
		m_enemies.push_back(temp_a);
	}

	

	m_board.draw();
	m_player.draw();
	for (list<Bullet>::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it) {
		it->draw();
		
	}
	for (list<Enemy>::iterator it = m_enemies.begin(); it != m_enemies.end(); ++it) {
		it->draw();
	}
}

float2 Game::getCoords()
{
	return { m_player.d.drect.x, m_player.d.drect.y };
}
