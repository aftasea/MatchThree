#pragma once
#ifndef TILE_H
#define TILE_H

#include <string>

class Sprite;

class Tile
{
public:
	Tile() : sprite(nullptr)
	{}
	~Tile();

	void initSprite(std::string path);
	void setPosition(int x, int y);

private:
	Sprite* sprite;
};

#endif // !TILE_H