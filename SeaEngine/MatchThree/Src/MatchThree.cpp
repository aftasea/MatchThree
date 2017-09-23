#include "MatchThree.h"
#include "Sprite.h"
#include "Tile.h"
#include <vector>

#include <cstdlib>
#include <ctime>

MatchThree::MatchThree()
{
	setup();
}

MatchThree::~MatchThree()
{
}

void MatchThree::update()
{
}

void MatchThree::render()
{
}

void MatchThree::setup()
{
	// game settings
	int xOffset = 64;
	int yOffset = 64;
	characters = {
		"res/images/test.png",
		"res/images/test2.png",
		"res/images/test3.png"
	};
	createBoard(xOffset, yOffset);
}

int getRandom(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

void MatchThree::createBoard(int xOffset, int yOffset)
{
	std::vector<std::vector<Tile*>> tiles;

	int startX = 200;
	int startY = 100;

	srand(static_cast<unsigned int>(time(0)));

	for (int x = 0; x < 6; x++) {
		std::vector<Tile*> row;
		for (int y = 0; y < 6; y++) {
			Tile* newTile = new Tile();
			newTile->initSprite(characters[getRandom(0, characters.size() - 1)]);
			newTile->setPosition(startX + (xOffset * x), startY + (yOffset * y));
			row.push_back(newTile);
		}
		tiles.push_back(row);
	}
}