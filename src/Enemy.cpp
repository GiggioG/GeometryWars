#include "Enemy.h"
#include "Game.h"


Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::update() {
	float2 playerCoords = Game::getCoords();

	float xDiff = playerCoords.x - d.drect.x;
	float yDiff = playerCoords.y - d.drect.y;

	d.angle = atan2(-yDiff, xDiff);

	acc.x += cos(d.angle);
	acc.y -= sin(d.angle);

	Entity::update();

	/// TODO:
	// (see: steering behaviours)
	// p + v*t = e + sqrt((e.x-(p+v*t).x)^2 + (e.y-(p+v*t).y)^2) * v_e * t

}

void Enemy::init()
{
	model_w = 100;
	model_h = 100;
	model_name = "Player1.bmp";

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


