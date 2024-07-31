#pragma once

#include "State.h"
#include "Board.h"
#include "Player.h"
#include "Enemy.h"

class Game : public State
{
public:

	Game();
	~Game();

	Board m_board;
	static Player m_player; 
	Enemy m_enemy;

	void init();
	void destroy();
	void run();
	static float2 getCoords() ;
};