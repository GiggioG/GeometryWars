#include "Game.h"
#include "InputManager.h"
#include "Chaser.h"
#include "Asteroid.h"
#include "Bouncer.h"

Player Game::m_player = Player();
list<Bullet*> Game::m_bullets = list<Bullet*>();
list<Enemy*> Game::m_enemies = list<Enemy*>();

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
	Chaser::model.init();
	Asteroid::model.init();
	Bouncer::model.init();
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
	for (list<Bullet*>::iterator it = m_bullets.begin(); it != m_bullets.end();) {
		(*it)->update();
		if ((*it)->toDelete) {
			list<Bullet*>::iterator it2 = it;
			++it;
			delete (*it2);
			m_bullets.erase(it2);
		}else {
			++it;
		}
	}
	for (list<Enemy*>::iterator it = m_enemies.begin(); it != m_enemies.end();) {
		(*it)->update();
		if ((*it)->toDelete) {
			list<Enemy*>::iterator it2 = it;
			++it;
			delete (*it2);
			m_enemies.erase(it2);
		}
		else {
			++it;
		}
	}

	if (!InputManager::m_joystickConnected) { /// TODO: this is only for developement debugging
		if (InputManager::m_keyboardState[SDL_SCANCODE_B]) {
			//cout << "b" << endl;

			Chaser* newChaser = new Chaser;
			newChaser->spawn(&Chaser::model);
			m_enemies.push_back(newChaser);
		}
	}else
	
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_A)) {
		Asteroid* newAsteroid = new Asteroid;
		newAsteroid->spawn(&Asteroid::model);
		m_enemies.push_back(newAsteroid);
	}
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_B)) {
		Chaser* newChaser = new Chaser;
		newChaser->spawn(&Chaser::model);
		m_enemies.push_back(newChaser);
	}
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_X)) {
		Bouncer* newBouncer = new Bouncer;
		newBouncer->spawn(&Bouncer::model);
		m_enemies.push_back(newBouncer);
	}

	

	m_board.draw();
	m_player.draw();
	for (list<Bullet*>::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it) {
		(*it)->draw();
		
	}
	for (list<Enemy*>::iterator it = m_enemies.begin(); it != m_enemies.end(); ++it) {
		(*it)->draw();
	}
}

float2 Game::getCoords() {
	return m_player.pos;
}
