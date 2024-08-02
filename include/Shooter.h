#pragma once
#include "Enemy.h"
#include "Bullet.h"

class Shooter : public Enemy {
public:
	Shooter();
	 ~Shooter();

	void shoot();
};