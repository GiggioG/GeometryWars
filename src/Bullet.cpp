#include "Bullet.h"

extern float deltaTime;

Bullet Bullet::model = Bullet();
Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::update() {
	pos.x += cos(angle) * speed * deltaTime;
	pos.y -= sin(angle) * speed * deltaTime;
	checkBounds();
	//D(speed);
	//D(d.drect.x);
	//D(d.drect.y);
	//D(d.angle);
}

void Bullet::init() {
	model_w = 50;
	model_h = 50;
	model_name = "Shield.bmp";
	speed = 20;

	model.d.drect.w = model_w;
	model.d.drect.h = model_h;
	model.d.drect.x = 700;
	model.d.drect.y = 700;
	model.pos = { 700, 700 };
	model.angle = 0;
	model.d.texture = loadTexture(model_name);
}

void Bullet::spawn(float2 startPos, float startAngle, bool shot_by) {
	toDelete = false;
	d = model.d;
	speed = model.speed;
	pos.x = startPos.x;
	pos.y = startPos.y;
	angle = startAngle;
	shot_by_player = shot_by;
}



