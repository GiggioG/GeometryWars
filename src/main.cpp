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
	    : make functions which can be constexpr constexpr
	    : make methods that don't modify the object "const"
	    : put const in method's arguments when adequate
	    : use std::list for bullets instead of vector
	    : fix shooting cooldown with some proper approach
	    : m_angle and pos for physics, d.* for drawing
	    : deltaTime
	    : bullets in Game/Board, out of bounds detection in Game/Board.update();
	    : make destruct, destroy and exit all to "destroy"
	TODO: fix all of Redi-1's hardcoding that does not require a config file
	TODO: draw different bullet texture by "shot_by_player"
	TODO: enemy predicts player trajectory
	    : construct enemies and bullets in-place, instead of using temporarys
	TODO: config file
*/