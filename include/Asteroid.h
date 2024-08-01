#pragma once

#include "Mover.h"

class Asteroid : public Mover {
public:
	Asteroid();
	~Asteroid();

	void init();
	void update() override;
};