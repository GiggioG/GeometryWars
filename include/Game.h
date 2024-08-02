#pragma once

#include "State.h"
#include "Board.h"
#include "Player.h"
#include "Enemy.h"
#include <list>

class Game : public State {
public:
	Game();
	~Game();

	Board m_board;
	static Player m_player;
	static list<Enemy*> m_enemies;
	static list<Bullet*> m_bullets;

	void init();
	void destroy();
	void run();
	static float2 getCoords();
private:
	void collideBullets();
	void collideEnemies();
};