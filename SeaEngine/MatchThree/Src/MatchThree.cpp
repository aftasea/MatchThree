#include "MatchThree.h"
#include "Sprite.h"

Sprite* sp1;
Sprite* sp2;

MatchThree::MatchThree()
{
	sp1 = new Sprite{ "res/images/test.png" };
	sp2 = new Sprite{ "res/images/game.png" };
	sp2->posX = 50;
	sp2->posY = 10;
}

MatchThree::~MatchThree()
{
	delete sp1;
	delete sp2;
}

void MatchThree::update()
{
}

void MatchThree::render()
{
}