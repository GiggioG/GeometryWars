#pragma once

#include "Presenter.h"
#include "Entity.h"

class Enemy : public Entity{
public:
	Enemy();
	~Enemy();
	static Enemy model;
	string model_name;
	int model_w;
	int model_h;
	
	void exit();
	void spawn();
	void checkBounds();
};