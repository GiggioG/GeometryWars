#pragma once

#include "Presenter.h"
#include "Entity.h"

class Enemy : public Entity{
public:
	Enemy();
	~Enemy();
	Enemy* model;
	string model_name;
	int model_w;
	int model_h;
	
	void update();
	void init();
	void spawn();
	void exit();

};