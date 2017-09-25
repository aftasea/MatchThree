#pragma once
#ifndef MATCHTHREE_H
#define MATCHTHREE_H

#include "IGame.h"
#include <vector>
#include <string>

#include "Settings.h"

class Tile;
class BlockShifter;

class MatchThree : public IGame
{
public:
	MatchThree();
	~MatchThree();

	static MatchThree& getInstance()
	{
		return (*instance);
	}

	virtual void update();
	virtual void render();

	std::vector<Tile*> getAllAdjacentTiles(int x, int y);
	void clearAllMatches(int x, int y, int id);
	void findNullTiles();

	bool matchFound;

private:
	static MatchThree* instance;

	void createBoard();
	int getRandomAvailableTileId(int posX, int posY, std::vector<Tile*> &col);
	void clearHorizontalMatches(int x, int y, int id);
	void clearVerticalMatches(int x, int y, int id);
	void MatchThree::shiftTilesDown(int initialX, int initialY);

	Settings settings;
	std::vector<std::vector<Tile*>> tiles;
	std::vector<BlockShifter*> shifts;
};

#endif // !MATCHTHREE_H