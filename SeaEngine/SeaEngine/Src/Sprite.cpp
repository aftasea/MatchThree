#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Engine.h"
#include "Utils.h"
#include <iostream>

Sprite::Sprite(int layer, std::string filepath) : posX(0), posY(0), path(filepath), isVisible(true)
{
	Engine::getInstance().registerRenderableObject(layer, this);
	id = Utils::getNewId();
}

Sprite::~Sprite()
{}

const std::string& Sprite::getPath() const
{
	return path;
}

int Sprite::getId() const
{
	return id;
}

bool operator== (const Sprite &s1, const Sprite &s2)
{
	return s1.id == s2.id;
}
