#include "Engine.h"
#include "MatchThree.h"

int main(int argc, char* args[])
{
	Engine engine;
	engine.Init(640, 480, "Match Three");
	MatchThree game;
	engine.Run(game);

	return 0;
}