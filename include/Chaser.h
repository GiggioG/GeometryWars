#pragma once

#include "Mover.h"

class Chaser : public Mover {
public:
	Chaser();
	~Chaser();
	
	static Chaser model;

	void init();
	void update();
};