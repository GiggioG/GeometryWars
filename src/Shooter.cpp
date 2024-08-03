#include "Shooter.h"
#include "InputManager.h"
#include "Game.h"

Shooter::Shooter()
{
}

Shooter::~Shooter()
{
}

void Shooter::shoot()
{
	float2 playerCoords = Game::getCoords();
	float2 diff = playerCoords - pos;

	angle = atan2(-diff.y, diff.x);
	Bullet* newBullet = new Bullet;
	newBullet->spawn(pos, angle, false, bullet_damage);
	Game::m_bullets.push_back(newBullet);
}

void Shooter::spawn(const Shooter* m)
{
	range = m->range;
	bullet_damage = m->bullet_damage;
	 
	Enemy::spawn(m);

}

