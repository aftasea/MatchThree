#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Engine.h"
#include <iostream>

Sprite::Sprite(std::string filepath) : posX(0), posY(0), path(filepath)
{
	Engine::getInstance().registerRenderableObject(this);
}

Sprite::~Sprite()
{}

const std::string& Sprite::getPath() const
{
	return path;
}
