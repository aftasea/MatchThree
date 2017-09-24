#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <string>

class Sprite
{
public:
	Sprite(int layer, std::string filepath);
	~Sprite();

	const std::string& getPath() const;

	int posX;
	int posY;
	bool isVisible;

private:
	std::string path;
};

#endif // !SPRITE_H