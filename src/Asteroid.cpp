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
	speed = 2;
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
	pos.x += cos(angle) * speed;
	pos.y -= sin(angle) * speed;
	lifespan = min(5000, lifespan + 1);
	if (lifespan>500) {
		checkBounds();
	}
}

void Asteroid::spawn(const Asteroid* model) {
	int rand_r = rand() % Presenter::m_SCREEN_HEIGHT - Presenter::m_SCREEN_HEIGHT / 2;
	int rand_c = rand() % Presenter::m_SCREEN_WIDTH - Presenter::m_SCREEN_WIDTH / 2;

	angle = atan2(-rand_r, rand_c);
	Enemy::spawn(model);
}