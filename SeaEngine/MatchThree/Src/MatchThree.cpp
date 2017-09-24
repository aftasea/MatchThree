#include "MatchThree.h"
#include "Sprite.h"
#include "Tile.h"
#include "Settings.h"
#include "Utils.h"
#include <vector>

#include <iostream>

MatchThree* MatchThree::instance = nullptr;

MatchThree::MatchThree() : matchFound(false)
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
		adjacentTiles.push_back(tiles[x - 1][y]);

	if (x < (settings.boardWidht - 1))
		adjacentTiles.push_back(tiles[x + 1][y]);

	if (y > 0)
		adjacentTiles.push_back(tiles[x][y - 1]);

	if (y < (settings.boardHeight - 1))
		adjacentTiles.push_back(tiles[x][y + 1]);

	return adjacentTiles;
}

void MatchThree::clearAllMatches(int x, int y, int id)
{
	clearHorizontalMatches(x, y, id);
	clearVerticalMatches(x, y, id);
}

void MatchThree::clearHorizontalMatches(int x, int y, int id)
{
	std::vector<Tile*> matchingTiles;

	// checking to the left
	int gridPos = x - 1;
	while (gridPos >= 0)
	{
		if (tiles[gridPos][y]->getId() != id)
			break;

		matchingTiles.push_back(tiles[gridPos][y]);
		--gridPos;
	}

	// checking to the right
	gridPos = x + 1;
	while (gridPos < settings.boardWidht)
	{
		if (tiles[gridPos][y]->getId() != id)
			break;

		matchingTiles.push_back(tiles[gridPos][y]);
		++gridPos;
	}

	if (matchingTiles.size() >= 2)
	{
		for (auto tile : matchingTiles)
		{
			tile->removeSprite();
		}
		matchFound = true;
	}
}

void MatchThree::clearVerticalMatches(int x, int y, int id)
{
	std::vector<Tile*> matchingTiles;

	// checking up
	int gridPos = y - 1;
	while (gridPos >= 0)
	{
		if (tiles[x][gridPos]->getId() != id)
			break;

		matchingTiles.push_back(tiles[x][gridPos]);
		--gridPos;
	}

	// checking down
	gridPos = y + 1;
	while (gridPos < settings.boardHeight)
	{
		if (tiles[x][gridPos]->getId() != id)
			break;

		matchingTiles.push_back(tiles[x][gridPos]);
		++gridPos;
	}

	if (matchingTiles.size() >= 2)
	{
		for (auto tile : matchingTiles)
		{
			tile->removeSprite();
		}
		matchFound = true;
	}
}

void MatchThree::findNullTiles()
{
	for (int x = 0; x < settings.boardWidht; ++x)
	{
		for (int y = settings.boardHeight - 1; y >= 0; --y)
		{
			if (!tiles[x][y]->hasSprite())
			{
				//addCoroutine(shiftTilesDown(x, y));
				shiftTilesDown(x, y);
				break;
			}
		}
	}
}

void MatchThree::shiftTilesDown(int x, int initialY)
{
	//isShifting = true;
	std::vector<Tile*> tilesOnTop;
	int nullCount = 0;

	for (int y = initialY; y >= 0; --y)
	{
		if (!tiles[x][y]->hasSprite())
			nullCount++;

		tilesOnTop.push_back(tiles[x][y]);
	}

	for (int i = 0; i < nullCount; i++) {
		//yield return new WaitForSeconds(shiftDelay);
		for (int k = 0; k < tilesOnTop.size() - 1; ++k)
		{
			/*renders[k].sprite = renders[k + 1].sprite;
			renders[k + 1].sprite = null;*/
			tilesOnTop[k]->swapSprite(tilesOnTop[k + 1]);
		}

	}
	//isShifting = false;
}
