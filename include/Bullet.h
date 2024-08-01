#pragma once 

#include "Entity.h"

class Bullet : public Entity {
public:
	Bullet();
	~Bullet();

	static Bullet model;
	string model_name;
	int model_w;
	int model_h;
	bool shot_by_player;

	void update();
	void init();
	void spawn(float2 pos, float angle, bool shot_by);
};