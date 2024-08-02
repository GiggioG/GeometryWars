#include "StateManager.h"
#include "World.h"

extern World world;

StateManager::StateManager()
{
	m_gameState = GAME_STATE::NONE;
	m_currState = nullptr;
}

StateManager::~StateManager()
{
	m_gameState = GAME_STATE::NONE;
	m_currState = nullptr;
}

void StateManager::changeGameState(GAME_STATE _state) {
	//destroyLastState();

	m_gameState = _state;
	initNewState();
}

void StateManager::initNewState()
{
	switch (m_gameState)
	{
	case GAME_STATE::NONE:
		world.destroy();
		
		return;
		break;
	case GAME_STATE::GAME:
		m_currState = m_game;
		break;
	case GAME_STATE::TITLE_SCREEN:
		m_titleScreen = new TitleScreen();
		m_currState = m_titleScreen;
		break;
	case GAME_STATE::END_SCREEN:
		m_endScreen = new EndScreen;
		m_currState = m_endScreen;
	default:
		break;
	}

	m_currState->init();
}

void StateManager::init(GAME_STATE _state)
{
	m_gameState = _state;
	m_game = new Game();

	initNewState();
}

void StateManager::run()
{
	m_currState->run();
}

void StateManager::destroyLastState()
{
	m_currState->destroy();
	
	delete m_currState;
	m_currState = nullptr;
}