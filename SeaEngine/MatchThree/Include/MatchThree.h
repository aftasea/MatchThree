#pragma once
#ifndef MATCHTHREE_H
#define MATCHTHREE_H

#include "IGame.h"
#include <vector>
#include <string>

class MatchThree : public IGame
{
public:
	MatchThree();
	~MatchThree();

	virtual void update();
	virtual void render();

private:
	void setup();
	void createBoard(int xOffset, int yOffset);

	std::vector<std::string> characters;
};

#endif // !MATCHTHREE_H