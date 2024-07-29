#pragma once

#include "Presenter.h"

class Player {
public:
	Player();
	~Player();

	void init();
	void update();
	void draw();
	void destruct();

	SDL_Texture* texture;
	float2 coord = {500, 500};
	float angle = 0;
	float speed = 5;
};