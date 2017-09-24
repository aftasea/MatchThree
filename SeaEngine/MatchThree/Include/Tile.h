#pragma once
#ifndef TILE_H
#define TILE_H

#include <string>
#include "Actor.h"
#include "IInputHandler.h"

class Sprite;

class Tile : public Actor, public IInputHandler
{
public:
	Tile();
	~Tile();

	virtual const Actor* getOwner() const;
	virtual void onMouseDown();

	int getId() const;

	void initSprite(int id, std::string path);
	void setPosition(int x, int y);
	void setDimensions(int w, int h);

private:
	Sprite* sprite;
	int id;
};

#endif // !TILE_H