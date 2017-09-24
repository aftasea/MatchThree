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

	virtual void update();
	virtual void render();

private:
	void createBoard();

	Settings settings;
	std::vector<std::vector<Tile*>> tiles;
};

#endif // !MATCHTHREE_H