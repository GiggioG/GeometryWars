#pragma once

#include "Engine.h"

class Board
{
public:
	Board();
	~Board();

	void init();
	void update();
	void draw() const;
	void destroy();

private:
	SDL_Texture* m_background;
};