#include "Enemy.h"
#include "Game.h"


Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	float2 playerCoords = Game::getCoords();
	if (d.drect.x > playerCoords.x) {
		d.drect.x -= speed;
	}
	else {
		d.drect.x += speed;
	}
	if (d.drect.y >playerCoords.y) {
		d.drect.y -= speed;
	}
	else {
		d.drect.y += speed;
	}

}

void Enemy::init()
{
	model_w = 100;
	model_h = 100;
	model_name = "NITE_gotovo_png.png";

	model = new Enemy;
	model->d.drect.w = model_w;
	model->d.drect.h = model_h;
	model->d.drect.x = 700;
	model->d.drect.y = 700;
	model->d.texture = loadTexture(model_name);
	
	
}

void Enemy::spawn()
{
	int dir = rand() % 4;
	d = model->d;
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


