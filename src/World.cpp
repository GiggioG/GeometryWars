#include "World.h"

float deltaTime;

World::World() {
	m_isRunning = true;
}

World::~World() {}

Uint64 currentTime = 0;
Uint64 lastTime = 0;

void World::init()
{
	m_soundManager.init();
	m_presenter.init();
	m_inputManager.init();
	m_stateManager.init(GAME_STATE::TITLE_SCREEN);

	currentTime = SDL_GetPerformanceCounter();
	lastTime = SDL_GetPerformanceCounter();
}


void World::run()
{
	m_inputManager.handleInput();

	lastTime = currentTime;
	currentTime = SDL_GetPerformanceCounter();
	deltaTime = (float)((currentTime - lastTime) * 1000.0f / (float)SDL_GetPerformanceFrequency());
	deltaTime /= 16.0f; /// TODO: config
	m_stateManager.run();

	m_presenter.draw();
}

void World::destroy() {
	m_soundManager.destroy();
	m_inputManager.destroy();
	m_presenter.destroy();
	m_isRunning = false;
}

bool World::isRunning() const {
	return m_isRunning;
}