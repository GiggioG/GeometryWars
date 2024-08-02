#include "Bouncer.h"
#include "Game.h"

Bouncer Bouncer::model = Bouncer();

Bouncer::Bouncer()
{
}

Bouncer::~Bouncer()
{
}

void Bouncer::init()
{
	/// TODO: config for these
	speed = 5;
	health = 25;
	model_w = 75;
	model_h = 75;
	model_name = "ZigZag.bmp";
	model.d.drect.w = model_w;
	model.d.drect.h = model_h;

	/// TODO: 700 is arbitrary, do something else more sensical

	model.d.drect.x = 700;
	model.d.drect.y = 700;
	model.pos = { 700, 700 };
	model.angle = 0;
	model.d.texture = loadTexture(model_name);
}

void Bouncer::update() {
	
	float2 new_pos = {pos.x,pos.y};
	new_pos.x += cos(angle) * speed;
	new_pos.y -= sin(angle) * speed;
	if (new_pos.x + (d.drect.w / 2) > Presenter::m_SCREEN_WIDTH || new_pos.x - (d.drect.w / 2) < 0  || new_pos.y - (d.drect.h / 2) < 0  || new_pos.y + (d.drect.h / 2) > Presenter::m_SCREEN_HEIGHT) {
		angle = angle / pi * 180;
		angle += rand() % 10 + 80;
		angle = angle * pi / 180;
		new_pos.x = pos.x;
		new_pos.y = pos.y;
	}
	
	pos.x = new_pos.x;
	pos.y = new_pos.y;
}

void Bouncer::spawn(const Bouncer* model) {
	int rand_r = rand() % Presenter::m_SCREEN_HEIGHT - Presenter::m_SCREEN_HEIGHT/2;
	int rand_c = rand() % Presenter::m_SCREEN_WIDTH - Presenter::m_SCREEN_WIDTH/2;

	angle = atan2(-rand_r, rand_c);

	Enemy::spawn(model);

	int dir = rand() % 4;
	switch (dir) {
	case 0:
		pos.x = 50;
		pos.y = 50;
		break;
	case 1:
		pos.x =  Presenter::m_SCREEN_WIDTH-50;
		pos.y = 50;
		break;
	case 2:
		pos.x = Presenter::m_SCREEN_WIDTH - 50;
		pos.y = Presenter::m_SCREEN_HEIGHT - 50;
		break;
	case 3:
		pos.x = 50;
		pos.y = Presenter::m_SCREEN_HEIGHT - 50;
		break;
	}
}