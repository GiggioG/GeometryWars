#include "Chaser.h"
#include "Game.h"

Chaser Chaser::model = Chaser();

Chaser::Chaser()
{
}

Chaser::~Chaser()
{
}

void Chaser::init()
{
	health = 25;
	model_w = 100;
	model_h = 100;
	model_name = "Player1.bmp";

	d.drect.w = model_w;
	d.drect.h = model_h;
	d.drect.x = 700;
	d.drect.y = 700;
	d.texture = loadTexture(model_name);
}

void Chaser::update() {
	float2 playerCoords = Game::getCoords();

	float xDiff = playerCoords.x - d.drect.x;
	float yDiff = playerCoords.y - d.drect.y;

	d.angle = atan2(-yDiff, xDiff);

	acc.x += cos(d.angle) * 0.4;
	acc.y -= sin(d.angle) * 0.4;

	Entity::update();

	/// TODO:
	// (see: steering behaviours)
	// p + v*t = e + sqrt((e.x-(p+v*t).x)^2 + (e.y-(p+v*t).y)^2) * v_e * t

}