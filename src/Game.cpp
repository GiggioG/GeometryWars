#include "Game.h"
#include "InputManager.h"
#include "Chaser.h"
#include "SChaser.h"
#include "Asteroid.h"
#include "World.h"
#include "Bouncer.h"
extern World world;

Player Game::m_player = Player();
list<Bullet*> Game::m_bullets = list<Bullet*>();
list<Enemy*> Game::m_enemies = list<Enemy*>();

Game::Game() {}

Game::~Game() {}

void Game::init()
{
	m_board.init();
	m_player.init();
	Chaser::model.init();
	Asteroid::model.init();
	Bouncer::model.init();
	Bullet::model.init();
	SChaser::model.init();
	//m_enemy.spawn();
}

void Game::destroy() {}

void Game::run() {
	if (!InputManager::m_joystickConnected) { /// TODO: this is only for developement debugging
		if (InputManager::m_keyboardState[SDL_SCANCODE_B]) {
			//cout << "b" << endl;

			Chaser* newChaser = new Chaser;
			newChaser->spawn(&Chaser::model);
			m_enemies.push_back(newChaser);
		}
	}else
	
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_A)) { /// TODO: actual spawning
		Asteroid* newAsteroid = new Asteroid;
		newAsteroid->spawn(&Asteroid::model);
		m_enemies.push_back(newAsteroid);
	}
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_X)) {
		Chaser* newChaser = new Chaser;
		newChaser->spawn(&Chaser::model);
		m_enemies.push_back(newChaser);
	}
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_B)) {
		Bouncer* newBouncer = new Bouncer;
		newBouncer->spawn(&Bouncer::model);
		m_enemies.push_back(newBouncer);
	}
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_Y)) {
		SChaser* newSChaser = new SChaser;
		newSChaser->spawn(&SChaser::model);
		m_enemies.push_back(newSChaser);
	}
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

	collideBullets();
	collideEnemies();

	if (m_player.toDelete) {
		cout << "Ded :(\n";
		world.m_stateManager.changeGameState(GAME_STATE::END_SCREEN);
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

void Game::collideBullets() {
	for (list<Bullet*>::iterator bull_it = m_bullets.begin(); bull_it != m_bullets.end(); ++bull_it) {
		Bullet& bull = **bull_it;
		RotatedRect bull_rrect = {
			{bull.d.drect.x, bull.d.drect.y, bull.d.drect.w, bull.d.drect.h},
			bull.d.angle
		};
		if (bull.shot_by_player) {
			for (list<Enemy*>::iterator enm_it = m_enemies.begin(); enm_it != m_enemies.end(); ++enm_it) {
				if (bull.toDelete) { break; }
				Enemy& enm = **enm_it;
				if (enm.toDelete) { continue; }
				RotatedRect enm_rrect = {
					{enm.d.drect.x, enm.d.drect.y, enm.d.drect.w, enm.d.drect.h},
					enm.d.angle
				};
				if (collRotatedRectRotatedRect(bull_rrect, enm_rrect)) {
					enm.health -= bull.damage;
					enm.checkHealth();
					bull.toDelete = true;
					break;
				}
			}
		} else if(!m_player.toDelete) {
			RotatedRect player_rrect = {
				{m_player.d.drect.x, m_player.d.drect.y, m_player.d.drect.w, m_player.d.drect.h},
				m_player.d.angle
			};
			if (collRotatedRectRotatedRect(bull_rrect, player_rrect)) {
				m_player.health -= bull.damage;
				m_player.checkHealth();
				bull.toDelete = true;
				continue;
			}
		}
	}
}

void Game::collideEnemies() {
	if (m_player.toDelete) { return; }
	RotatedRect player_rrect = {
		{m_player.d.drect.x, m_player.d.drect.y, m_player.d.drect.w, m_player.d.drect.h},
		m_player.d.angle
	};
	for (list<Enemy*>::iterator enm_it = m_enemies.begin(); enm_it != m_enemies.end(); ++enm_it) {
		Enemy& enm = **enm_it;
		if (enm.toDelete) { continue; }
		RotatedRect enm_rrect = {
			{enm.d.drect.x, enm.d.drect.y, enm.d.drect.w, enm.d.drect.h},
			enm.d.angle
		};
		if (collRotatedRectRotatedRect(enm_rrect, player_rrect)) {
			m_player.health -= enm.health;
			m_player.checkHealth();
			enm.toDelete = true;
		}
	}
}
