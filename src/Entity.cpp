#include "Entity.h"

extern float deltaTime;

Entity::Entity() {
}

Entity::~Entity() {
}

void Entity::draw() {
	d.drect.x = pos.x - d.drect.w / 2;
	d.drect.y = pos.y - d.drect.h / 2;
	d.angle = angle - M_PI / 2;
	drawObject(d);
}

void Entity::update() {
	/// friction
	float frictionCoefficient = 0.05; /// TODO: config
	acc += (-vel * frictionCoefficient) * deltaTime;

	vel += acc * deltaTime;
	pos += vel * deltaTime;
	acc.reset();

	checkBounds();
}


void Entity::init() {
	toDelete = true;
}

void Entity::destroy() {
	SDL_DestroyTexture(d.texture);
}

void Entity::checkBounds() {
	if (pos.x > Presenter::m_SCREEN_WIDTH || pos.x < 0 || pos.y<0 || pos.y>Presenter::m_SCREEN_HEIGHT) {
		toDelete = true;
	}
}

void Entity::checkHealth() {
	if (health <= 0) {
		toDelete = true;
	}
}