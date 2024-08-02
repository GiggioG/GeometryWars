#include "Game.h"
#include "InputManager.h"
#include "Chaser.h"
#include "Asteroid.h"
#include "World.h"
#include "Bouncer.h"
extern World world;

Player Game::m_player = Player();
list<Bullet*> Game::m_bullets = list<Bullet*>();
list<Enemy*> Game::m_enemies = list<Enemy*>();

Game::Game() {}

Game::~Game() {}

void Game::init() {
	m_board.init();
	m_player.init();
	Chaser::model.init();
	Asteroid::model.init();
	Bouncer::model.init();
	Bullet::model.init();
}

void Game::destroy() {}

void Game::run() {
	if (!InputManager::m_joystickConnected) { /// TODO: this is only for developement debugging
		if (InputManager::m_keyboardState[SDL_SCANCODE_A]) { /// TODO: actual spawning
			summon<Asteroid>();
		}
		if (InputManager::m_keyboardState[SDL_SCANCODE_X]) {
			summon<Chaser>();
		}
		if (InputManager::m_keyboardState[SDL_SCANCODE_B]) {
			summon<Bouncer>();
		}
	}else
	
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_A)) { /// TODO: actual spawning
		summon<Asteroid>();
	}
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_X)) {
		summon<Chaser>();
	}
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_B)) {
		summon<Bouncer>();
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
			if (m_enemies.empty()) { lastWaveDefeated = SDL_GetTicks(); }
		}
		else {
			++it;
		}
	}

	summonWaveIfNecessary();

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

void Game::summonWaveIfNecessary() {
	if (!m_enemies.empty()) { return; }
	Time currTime = SDL_GetTicks();
	if (currTime - lastWaveDefeated < 3000) { return; } /// TODO: config
	waveNumber++;
	summon<Asteroid>(waveNumber / 3);
	summon<Chaser>(3 + waveNumber / 3);
	summon<Bouncer>(4 + waveNumber / 2);
}

void Game::collideBullets() {
	for (list<Bullet*>::iterator bull_it = m_bullets.begin(); bull_it != m_bullets.end(); ++bull_it) {
		Bullet& bull = **bull_it;
		RotatedRect bull_rrect = bull.getRotatedRect();
		if (bull.shot_by_player) {
			for (list<Enemy*>::iterator enm_it = m_enemies.begin(); enm_it != m_enemies.end(); ++enm_it) {
				if (bull.toDelete) { break; }
				Enemy& enm = **enm_it;
				if (enm.toDelete) { continue; }
				RotatedRect enm_rrect = enm.getRotatedRect();
				if (collRotatedRectRotatedRect(bull_rrect, enm_rrect)) {
					enm.health -= bull.damage;
					enm.checkHealth();
					bull.toDelete = true;
					break;
				}
			}
		} else if(!m_player.toDelete) {
			RotatedRect player_rrect = m_player.getRotatedRect();
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
	RotatedRect player_rrect = m_player.getRotatedRect();
	for (list<Enemy*>::iterator enm_it = m_enemies.begin(); enm_it != m_enemies.end(); ++enm_it) {
		Enemy& enm = **enm_it;
		if (enm.toDelete) { continue; }
		RotatedRect enm_rrect = enm.getRotatedRect();
		if (collRotatedRectRotatedRect(enm_rrect, player_rrect)) {
			m_player.health -= enm.health;
			m_player.checkHealth();
			enm.toDelete = true;
		}
	}
}

template<typename En>
void Game::summon(int amount) {
	for (int i = 0; i < amount; i++) {
		En* newEnemy = new En;
		newEnemy->spawn(&En::model);
		m_enemies.push_back(newEnemy);
	}
}