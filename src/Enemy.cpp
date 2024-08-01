#include "Enemy.h"
#include "Game.h"

Enemy Enemy:: model = Enemy();

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::init()
{
	model.d.drect.w = model_w;
	model.d.drect.h = model_h;
	model.d.drect.x = 700;
	model.d.drect.y = 700;
	model.d.texture = loadTexture(model_name);
}

void Enemy::spawn()
{
	int dir = rand() % 4;
	d = model.d;
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