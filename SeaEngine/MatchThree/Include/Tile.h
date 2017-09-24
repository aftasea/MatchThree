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

	int getId() const;

	void initSprite(int id, std::string path);
	void setPosition(int x, int y);

private:
	Sprite* sprite;
	int id;
};

#endif // !TILE_H