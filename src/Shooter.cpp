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
	Bullet* newBullet = new Bullet;
	newBullet->spawn(pos, atan2(Game::getCoords().y, Game::getCoords().x), false, bullet_dmg);
	Game::m_bullets.push_back(newBullet);
}

