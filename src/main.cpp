#include "World.h"

#undef main

World world;

int main(int argc, char* argv[])
{
	srand(time(0));
	world.init();

	while(world.isRunning())
	{
		world.run();
	}

	return 0;
}

/***
	TODO: make functions which can be constexpr constexpr
	TODO: make methods that don't modify the object "const"
	TODO: put const in method's arguments when adequate
	TODO: use std::list for bullets instead of vector
	TODO: shooting cooldown
	TODO: m_angle and pos for physics, d.* for drawing
*/