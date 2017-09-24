#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Engine.h"
#include <iostream>

Sprite::Sprite(int layer, std::string filepath) : posX(0), posY(0), path(filepath), isVisible(true)
{
	Engine::getInstance().registerRenderableObject(layer, this);
}

Sprite::~Sprite()
{}

const std::string& Sprite::getPath() const
{
	return path;
}

bool operator== (const Sprite &s1, const Sprite &s2)
{
	/*return (s1.posX == s2.posX &&
		s1.posY == s2.posY &&
		s1.path == s2.path);*/
	return false;
}
