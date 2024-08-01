#include "Entity.h"

extern float deltaTime;

Entity::Entity() {
}

Entity::~Entity() {
}

void Entity::draw()  {
	drawObject(d, float(d.angle - M_PI / 2));
}

void Entity::update() {
	/// friction
	float frictionCoefficient = 0.05; /// TODO: config
	acc.x += (-vel.x * frictionCoefficient) * deltaTime;
	acc.y += (-vel.y * frictionCoefficient) * deltaTime;

	vel = { vel.x + acc.x * deltaTime , vel.y + acc.y * deltaTime };
	d.drect.x = d.drect.x + vel.x * deltaTime;
	d.drect.y = d.drect.y + vel.y * deltaTime;
	acc = { 0, 0 };

	checkBounds();
}


void Entity::init() {
	toDelete = true;
}

void Entity::exit() {
	SDL_DestroyTexture(d.texture);
}

void Entity::checkBounds() {
	if (d.drect.x > Presenter::m_SCREEN_WIDTH || d.drect.x < 0 || d.drect.y<0 || d.drect.y>Presenter::m_SCREEN_HEIGHT) {
		toDelete = true;
	}
}
