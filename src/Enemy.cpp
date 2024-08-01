#include "Enemy.h"
#include "Game.h"


Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}



void Enemy::spawn(const Enemy * m)
{
	int dir = rand() % 4;
	d = m->d;
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

void Enemy::exit() {

}

void Enemy::checkBounds() {

}