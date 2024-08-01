#include "Enemy.h"
#include "Game.h"


Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}



void Enemy::spawn(Enemy *m)
{
	int dir = rand() % 4;
	d = m->d;
	switch (dir) {
	case 0:
		d.drect.x = rand() % Presenter::m_SCREEN_WIDTH;
		d.drect.y = ( - rand() % 400) - 100;
		break;
	case 1:
		d.drect.x = (rand() % 400) + 100 + Presenter::m_SCREEN_WIDTH;
		d.drect.y = rand()% Presenter::m_SCREEN_HEIGHT;
		break;
	case 2:
		d.drect.x = rand() % Presenter::m_SCREEN_WIDTH;
		d.drect.y = (rand() % 400) + 100 + Presenter::m_SCREEN_HEIGHT;
		break;
	case 3:
		d.drect.x = -(rand() % 400) - 100;
		d.drect.y = rand() % Presenter::m_SCREEN_HEIGHT;
		break;
	}
}

void Enemy::exit() {

}

void Enemy::checkBounds() {

}