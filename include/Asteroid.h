#pragma once

#include "Mover.h"

class Asteroid : public Mover {
public:
	Asteroid();
	~Asteroid();

	static Asteroid model;
	void init();
	void update() override;
};