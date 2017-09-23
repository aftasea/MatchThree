#pragma once
#ifndef MATCHTHREE_H
#define MATCHTHREE_H

#include "IGame.h"

class MatchThree : public IGame
{
public:
	MatchThree();
	~MatchThree();

	virtual void Update();
	virtual void Render();
};

#endif // !MATCHTHREE_H