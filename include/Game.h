#pragma once

#include "State.h"
#include "Board.h"
#include "Player.h"

class Game : public State
{
public:

	Game();
	~Game();

	Board m_board;
	Player m_player;

	void init();
	void destroy();
	void run();
};