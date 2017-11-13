#include "Engine.h"
#include "MatchThree.h"

int main(int argc, char* args[])
{
	Sea::Engine& engine = Sea::Engine::getInstance();
	engine.init(800, 600, "Match Three");
	MatchThree game;
	engine.run(game);

	return 0;
}