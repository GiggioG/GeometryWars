#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::draw()
{
	d.angle = (angle - M_PI / 2);
	drawObject(d);
}


void Entity::init()
{
}

void Entity::exit()
{
	SDL_DestroyTexture(d.texture);
}
