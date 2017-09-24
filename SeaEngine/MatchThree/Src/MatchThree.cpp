#include "MatchThree.h"
#include "Sprite.h"
#include "Tile.h"
#include "Settings.h"
#include "Utils.h"
#include <vector>

#include <iostream>

MatchThree* MatchThree::instance = nullptr;

MatchThree::MatchThree()
{
	if (instance == nullptr)
		instance = this;
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
		std::vector<Tile*> col;
		for (int y = 0; y < settings.boardHeight; ++y)
		{
			int id = getRandomAvailableTileId(x, y, col);
			Tile* newTile = new Tile(x, y);
			newTile->initSprite(id, settings.characters[id]);
			newTile->setPosition(settings.boardStartX + (settings.tileXOffset * x), settings.boardStartY + (settings.tileYOffset * y));
			newTile->setDimensions(settings.tileXOffset, settings.tileYOffset);
			col.push_back(newTile);
		}
		tiles.push_back(col);
	}
}

int MatchThree::getRandomAvailableTileId(int posX, int posY, std::vector<Tile*> &col)
{
	std::vector<int> possibleCharacters;
	for (int i = 0; i < settings.characters.size(); ++i)
	{
		if ((posX > 0 && i == tiles[posX - 1][posY]->getId()) || (posY > 0 && i == col[posY - 1]->getId()))
			continue;
		possibleCharacters.push_back(i);
	}

	return possibleCharacters[Utils::getRandom(0, possibleCharacters.size() - 1)];
}

std::vector<Tile*> MatchThree::getAllAdjacentTiles(int x, int y)
{
	std::vector<Tile*> adjacentTiles;

	if (x > 0)
		adjacentTiles.push_back(instance->tiles[x - 1][y]);

	if (x < (instance->settings.boardWidht - 1))
		adjacentTiles.push_back(instance->tiles[x + 1][y]);

	if (y > 0)
		adjacentTiles.push_back(instance->tiles[x][y - 1]);

	if (y < (instance->settings.boardHeight - 1))
		adjacentTiles.push_back(instance->tiles[x][y + 1]);

	return adjacentTiles;
}