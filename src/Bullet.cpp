#include "Bullet.h"

Bullet Bullet::model = Bullet();
Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::update()
{
	d.drect.x += cos(d.angle)*speed;
	d.drect.y -= sin(d.angle)*speed;
	if (d.drect.x > Presenter::m_SCREEN_WIDTH || d.drect.x < 0 || d.drect.y<0 || d.drect.y>Presenter::m_SCREEN_HEIGHT) {
		toDelete = true;
	}
	//D(speed);
	//D(d.drect.x);
	//D(d.drect.y);
	//D(d.angle);
}

void Bullet::init()
{
	model_w = 50;
	model_h = 50;
	model_name = "Shield.bmp";
	speed = 20;

	model.d.drect.w = model_w;
	model.d.drect.h = model_h;
	model.d.drect.x = 700;
	model.d.drect.y = 700;
	model.d.texture = loadTexture(model_name);
}

void Bullet::spawn(float2 pos, float angle, bool shot_by)
{
	toDelete = false;
	d = model.d;
	speed = model.speed;
	d.drect.x = pos.x;
	d.drect.y = pos.y;
	d.angle = angle;
	shot_by_player = shot_by;

}



