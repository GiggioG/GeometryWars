#include "Asteroid.h"
#include "Game.h"

Asteroid Asteroid::model = Asteroid();

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
	model_name = "rock.bmp";

	model.d.drect.w = model_w;
	model.d.drect.h = model_h;
	model.d.drect.x = 700;
	model.d.drect.y = 700;
	model.d.texture = loadTexture(model_name);
}

void Asteroid::update() {
	d.angle = (rand() % 360)*pi/180;


	d.drect.x += cos(d.angle) * speed;
	d.drect.y -= sin(d.angle) * speed;
}