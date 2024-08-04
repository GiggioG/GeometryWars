#pragma once

#include "Shooter.h"

class SChaser : public Shooter {
public:
	SChaser();
	~SChaser();

	static SChaser model;

	void init();
	void update();

};