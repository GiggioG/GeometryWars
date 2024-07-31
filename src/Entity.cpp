#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::draw() {
	d.angle = (d.angle - M_PI / 2);
	drawObject(d);
}

void Entity::update() {
	/// friction
	float frictionCoefficient = 0.05; /// TODO: config
	acc.x += -vel.x * frictionCoefficient;
	acc.y += -vel.y * frictionCoefficient;

	vel = { vel.x + acc.x , vel.y + acc.y };
	d.drect.x = d.drect.x + vel.x;
	d.drect.y = d.drect.y + vel.y;
	acc = { 0, 0 };
}


void Entity::init()
{
}

void Entity::exit()
{
	SDL_DestroyTexture(d.texture);
}
