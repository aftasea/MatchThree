#include "MatchThree.h"
#include "Sprite.h"
#include "Tile.h"
#include "Settings.h"
#include "Utils.h"
#include <vector>

#include <iostream>

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
	for (int y = 0; y < settings.boardHeight; ++y)
	{
		std::vector<Tile*> row;
		for (int x = 0; x < settings.boardWidht; ++x)
		{
			int id = getRandomAvailableTileId(x, y, row);
			Tile* newTile = new Tile();
			newTile->initSprite(id, settings.characters[id]);
			newTile->setPosition(settings.boardStartX + (settings.tileXOffset * x), settings.boardStartY + (settings.tileYOffset * y));
			row.push_back(newTile);
		}
		tiles.push_back(row);
	}
}

int MatchThree::getRandomAvailableTileId(int posX, int posY, std::vector<Tile*> &row)
{
	std::vector<int> possibleCharacters;
	for (int i = 0; i < settings.characters.size(); ++i)
	{
		if ((posX > 0 && i == row[posX - 1]->getId()) || (posY > 0 && i == tiles[posY - 1][posX]->getId()))
			continue;
		possibleCharacters.push_back(i);
	}

	return possibleCharacters[Utils::getRandom(0, possibleCharacters.size() - 1)];
}