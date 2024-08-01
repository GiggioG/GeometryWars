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
	
	void destroy();
	void spawn(const Enemy* m);
	void checkBounds();
};