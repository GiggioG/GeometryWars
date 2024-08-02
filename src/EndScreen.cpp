#include "EndScreen.h"
#include "World.h"

extern World world;

EndScreen::EndScreen() {}
EndScreen::~EndScreen() {}

void EndScreen::init() {
	m_endScreenTexture = loadTexture("EndGameScreen.bmp");
}

void EndScreen::run() {
	drawObject(m_endScreenTexture);

	if (isAnyKeyPressed()) {
		world.m_stateManager.changeGameState(GAME_STATE::NONE);
		return;
	}
}

void EndScreen::destroy() {
	SDL_DestroyTexture(m_endScreenTexture);
}