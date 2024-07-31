#pragma once

#include "Presenter.h"

class Entity {

public:
	Entity();
	virtual ~Entity();

	Drawable d;
	//float angle = 0;
	float speed = 3;

	virtual void init();
	virtual void draw();
	virtual void update()=0;
	virtual void exit();
};