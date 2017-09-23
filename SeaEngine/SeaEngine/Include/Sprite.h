#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <string>

class Sprite
{
public:
	Sprite(std::string filepath);
	~Sprite();

	const std::string& getPath() const;

	int posX;
	int posY;

private:
	std::string path;
};

#endif // !SPRITE_H