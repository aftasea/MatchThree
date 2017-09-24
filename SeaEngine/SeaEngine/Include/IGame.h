#pragma once
#ifndef I_GAME_H
#define I_GAME_H

class IGame
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif // !I_GAME_H