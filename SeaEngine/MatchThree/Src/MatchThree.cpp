#include "MatchThree.h"
#include "Sprite.h"
#include "Tile.h"
#include "Settings.h"
#include "Utils.h"
#include <vector>

MatchThree::MatchThree()
{
	createBoard();
}

MatchThree::~MatchThree()
{
	for (auto &row : tiles)
	{
		for (auto &tile : row)
		{
			delete tile;
		}
	}

	tiles.clear();
}

void MatchThree::update()
{
}

void MatchThree::render()
{
}

void MatchThree::createBoard()
{
	for (int x = 0; x < settings.boardWidht; ++x)
	{
		std::vector<Tile*> row;
		for (int y = 0; y < settings.boardHeight; ++y)
		{
			Tile* newTile = new Tile();
			newTile->initSprite(settings.characters[Utils::getRandom(0, settings.characters.size() - 1)]);
			newTile->setPosition(settings.boardStartX + (settings.tileXOffset * x), settings.boardStartY + (settings.tileYOffset * y));
			row.push_back(newTile);
		}
		tiles.push_back(row);
	}
}