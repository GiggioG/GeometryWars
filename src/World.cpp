#include "World.h"

World::World()
{
	m_isRunning = true;
}

World::~World()
{

}

void World::init()
{
	m_soundManager.init();
	m_presenter.init();
	m_inputManager.init();
	m_stateManager.init(GAME_STATE::GAME);
}

void World::run()
{
	m_inputManager.handleInput();

	m_stateManager.run();

	m_presenter.draw();
}

void World::destroy()
{
	m_soundManager.destroy();
	m_inputManager.destroy();
	m_presenter.destroy();
}

bool World::isRunning()
{
	return m_isRunning;
}