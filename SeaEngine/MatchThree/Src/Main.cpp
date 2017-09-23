#include "Engine.h"
#include "MatchThree.h"

int main(int argc, char* args[])
{
	Engine engine;
	engine.init(640, 480, "Match Three");
	MatchThree game;
	engine.run(game);

	return 0;
}