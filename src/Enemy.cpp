#include "Enemy.h"
#include "Game.h"


Enemy::Enemy() {}
Enemy::~Enemy() {}

void Enemy::spawn(const Enemy * m)
{
	d = m->d;
	health = m->health;
	speed = m->speed;
	model_name = m->model_name;
	int dir = rand() % 4;
	switch (dir) {
	case 0:
		pos.x = rand() % Presenter::m_SCREEN_WIDTH;
		pos.y = ( - rand() % 400) - 100;
		break;
	case 1:
		pos.x = (rand() % 400) + 100 + Presenter::m_SCREEN_WIDTH;
		pos.y = rand()% Presenter::m_SCREEN_HEIGHT;
		break;
	case 2:
		pos.x = rand() % Presenter::m_SCREEN_WIDTH;
		pos.y = (rand() % 400) + 100 + Presenter::m_SCREEN_HEIGHT;
		break;
	case 3:
		pos.x = -(rand() % 400) - 100;
		pos.y = rand() % Presenter::m_SCREEN_HEIGHT;
		break;
	}
}

void Enemy::destroy() {}
void Enemy::checkBounds() {}