#pragma once

#include "Presenter.h"

class Entity {

public:
	Entity();
	virtual ~Entity();

	Drawable d;
	float2 vel = { 0, 0 };
	float2 acc = { 0, 0 };
	float speed = 3;

	virtual void init();
	virtual void draw();
	virtual void update();
	virtual void exit();
};