#include "Chaser.h"
#include "Game.h"

Chaser Chaser::model = Chaser();

Chaser::Chaser()
{
}

Chaser::~Chaser()
{
}

void Chaser::init() {
	/// TODO: config for these
	/// TODO: 700 is arbitrary, do something else more sensical

	model.health = 25;
	model_w = 100;
	model_h = 100;
	model_name = "Player1.bmp";

	model.d.drect.w = model_w;
	model.d.drect.h = model_h;
	model.d.drect.x = 700;
	model.d.drect.y = 700;
	model.pos = { 700, 700 };
	model.angle = 0;
	model.d.texture = loadTexture(model_name);
}

void Chaser::update() {
	float2 playerCoords = Game::getCoords();
	float2 diff = playerCoords - pos;

	angle = atan2(-diff.y, diff.x);

	acc.x += cos(angle) * 0.4; /// TODO: config
	acc.y -= sin(angle) * 0.4;

	Entity::update();
	if (health > 0) {
		toDelete = false;
	}

	/// TODO:
	// (see: steering behaviours)
	// p + v*t = e + sqrt((e.x-(p+v*t).x)^2 + (e.y-(p+v*t).y)^2) * v_e * t
}