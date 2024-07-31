#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::draw()
{
	d.angle = (d.angle - M_PI / 2);
	drawObject(d);
}


void Entity::init()
{
}

void Entity::exit()
{
	SDL_DestroyTexture(d.texture);
}
