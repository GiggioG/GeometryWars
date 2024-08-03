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

	Drawable aimer;

	void init();
	void update();
	void shoot();
	void checkBounds();
	void draw();

};