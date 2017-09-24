#pragma once
#ifndef MATCHTHREE_H
#define MATCHTHREE_H

#include "IGame.h"
#include <vector>
#include <string>

#include "Settings.h"

class Tile;

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

	bool matchFound;

private:
	static MatchThree* instance;

	void createBoard();
	int getRandomAvailableTileId(int posX, int posY, std::vector<Tile*> &col);
	void clearHorizontalMatches(int x, int y, int id);
	void clearVerticalMatches(int x, int y, int id);
	std::vector<Tile*> findMatches(int x, int y, int id);

	Settings settings;
	std::vector<std::vector<Tile*>> tiles;
};

#endif // !MATCHTHREE_H