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
	/// TODO: config for these
	speed = 1;
	health = 75;
	model_w = 200;
	model_h = 200;
	model_name = "rock.bmp";
	model.d.drect.w = model_w;
	model.d.drect.h = model_h;

	/// TODO: 700 is arbitrary, do something else more sensical

	model.d.drect.x = 700;
	model.d.drect.y = 700;
	model.pos = { 700, 700 };
	model.angle = 0;
	model.d.texture = loadTexture(model_name);
}

void Asteroid::update() {
	angle = (rand() % 360)*pi/180;

	pos.x += cos(angle) * speed;
	pos.y -= sin(angle) * speed;
}