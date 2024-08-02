#pragma once

#include "Mover.h"

class Bouncer : public Mover {
public:
	Bouncer();
	~Bouncer();

	static Bouncer model;
	void init();
	void update();
	void spawn(const Bouncer* model);
};