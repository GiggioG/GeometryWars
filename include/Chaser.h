#pragma once

#include "Mover.h"

class Chaser : public Mover {
public:
	Chaser();
	~Chaser();

	void init();
	void update();
};