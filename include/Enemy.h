#pragma once

#include "Presenter.h"
#include "Entity.h"

class Enemy : public Entity{
public:
	Enemy();
	~Enemy();
	string model_name;
	int model_w;
	int model_h;
	
	void exit();
	void spawn(Enemy* m);
	void checkBounds();
};