#pragma once

#include "Board.h"
#include "TitleScreen.h"
#include "Game.h"
#include "EndScreen.h"

enum class GAME_STATE
{
	NONE = 0,
	GAME = 1,
	TITLE_SCREEN = 2,
	END_SCREEN = 3
};

class StateManager
{
public:
	StateManager();
	~StateManager();

	GAME_STATE m_gameState;

	Game* m_game;
	TitleScreen* m_titleScreen;
	EndScreen* m_endScreen;

	State* m_currState;

	void init(GAME_STATE _state);
	void run();

	void changeGameState(GAME_STATE _state);

private:
	void initNewState();
	void destroyLastState();
};