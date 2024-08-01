#pragma once

#include "Presenter.h"
#include "Entity.h"
#include "Bullet.h"
#include<vector>

class Player : public Entity {
public:
	Player();
	~Player();

	bool m_aiming;

	void init();
	void update();
	void shoot();
};