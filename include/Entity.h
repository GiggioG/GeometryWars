#pragma once

#include "Presenter.h"

class Entity {

public:
	Entity();
	virtual ~Entity();

	Drawable d;
	float2 pos = { 0, 0 };
	float2 vel = { 0, 0 };
	float2 acc = { 0, 0 };
	float angle;
	float speed = 3; /// TODO: config
	int health;
	bool toDelete = false;

	virtual void init();
	virtual void draw();
	virtual void update();
	virtual void destroy();
	virtual void checkBounds();
	virtual void checkHealth();
};