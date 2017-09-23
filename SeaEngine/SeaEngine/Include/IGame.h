#pragma once
#ifndef IGAME_H
#define IGAME_H

class IGame
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif // !IGAME_H