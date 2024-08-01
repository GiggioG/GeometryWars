#pragma once

#include "Presenter.h"
#include "Entity.h"
#include "Bullet.h"
#include<vector>

class Player : public Entity {
public:
	Player();
	~Player();

	float m_angle;
	bool m_aiming;

	void init();
	void update();
	void shoot();
};