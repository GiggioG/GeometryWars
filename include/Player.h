#pragma once

#include "Presenter.h"
#include "Entity.h"

class Player : public Entity {
public:
	Player();
	~Player();

	float m_angle;

	void init();
	void update();

};