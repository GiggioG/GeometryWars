#pragma once
#include "Enemy.h"
#include "Bullet.h"

class Shooter : public Enemy {
public:
	Shooter();
	 ~Shooter();

	 static Shooter model;

	 Time lastShotTimeEnemy = 0;
	 int range;
	 int bullet_damage;

	void shoot();
	void spawn(const Shooter* m);
};