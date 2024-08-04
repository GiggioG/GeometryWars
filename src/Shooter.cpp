#include "Shooter.h"
#include "InputManager.h"
#include "Game.h"

extern float deltaTime;

Shooter::Shooter()
{
}

Shooter::~Shooter()
{
}




void Shooter::shoot()
{
	Time currTime = SDL_GetTicks();

	if ((currTime - lastShotTimeEnemy) > 200) {
		float2 playerCoords = Game::getCoords();
		float2 diff = playerCoords - pos;
		lastShotTimeEnemy = currTime;

		angle = atan2(-diff.y, diff.x);
		Bullet* newBullet = new Bullet;
		newBullet->spawn(pos, angle, false, bullet_damage);
		Game::m_bullets.push_back(newBullet);
	}
	
}

void Shooter::spawn(const Shooter* m)
{
	range = m->range;
	bullet_damage = m->bullet_damage;
	 
	Enemy::spawn(m);

}

