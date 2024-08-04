#pragma once

#include "Mover.h"

class Asteroid : public Mover {
public:
	Asteroid();
	~Asteroid();

	int lifespan = 0;

	static Asteroid model;
	void init();
	void update();
	void spawn(const Asteroid* model);
};