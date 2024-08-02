#pragma once

#include "defines.h"
#include "State.h"

class EndScreen : public State
{
public:
	EndScreen();
	~EndScreen();

	void init();
	void run();
	void destroy();

private:
	SDL_Texture* m_endScreenTexture;
};