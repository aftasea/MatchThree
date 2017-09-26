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
	Tile(int gridPositionX, int gridPositionY);
	~Tile();

	virtual const Actor* getOwner() const;
	virtual void onMouseDown();

	int getId() const;
	bool hasSprite() const;
	int getGridPosX() const;
	int getGridPosY() const;

	void initSprite(int id, std::string path);
	void setPosition(int x, int y);
	void setDimensions(int w, int h);
	void removeSprite();
	void swapSprite(Tile* newTile);
	void setSpriteFrom(Tile* tile);
	void assignNewSprite(int spriteId, std::string path);
	void clearMatches();

private:
	void select();
	void deselect();

	static Tile* previousSelected;
	static Sprite* selectedSprite;

	Sprite* sprite;
	int id;
	bool isSelected = false;
	int gridPosX;
	int gridPosY;
};

#endif // !TILE_H