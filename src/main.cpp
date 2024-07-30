#include "World.h"

#undef main

World world;

int main(int argc, char* argv[])
{
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
*/