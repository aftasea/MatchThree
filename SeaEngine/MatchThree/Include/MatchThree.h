#pragma once
#ifndef MATCHTHREE_H
#define MATCHTHREE_H

#include "IGame.h"

class MatchThree : public IGame
{
public:
	MatchThree();
	~MatchThree();

	virtual void update();
	virtual void render();
};

#endif // !MATCHTHREE_H