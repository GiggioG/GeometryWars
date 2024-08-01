#include "Asteroid.h"
#include "Game.h"

Asteroid::Asteroid()
{
}

Asteroid::~Asteroid()
{
}

void Asteroid::init()
{
	speed = 1;
	health = 75;
	model_w = 200;
	model_h = 200;
	model_name = "Shield.bmp";
	Enemy::init();
}

void Asteroid::update() {
	d.angle = (rand() % 360)*pi/180;


	d.drect.x += cos(d.angle) * speed;
	d.drect.y -= sin(d.angle) * speed;
	cout << "test" << endl;


	

}