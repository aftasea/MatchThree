#include "Tile.h"
#include "Sprite.h"
#include "Engine.h"
#include <iostream>

Tile::Tile() : sprite(nullptr)
{
	Engine::getInstance().registerInputHandler(this);
}

Tile::~Tile()
{
	if (sprite != nullptr)
	{
		delete sprite;
		sprite = nullptr;
	}
}

const Actor* Tile::getOwner() const
{
	return this;
}

void Tile::onMouseDown()
{
	std::cout << "Clicked! id: " << id << ", x: " << posX << ", y: " << posY << std::endl;
}

int Tile::getId() const
{
	return id;
}

void Tile::initSprite(int id, std::string path)
{
	this->id = id;
	if (sprite == nullptr)
		sprite = new Sprite{ path };
}

void Tile::setPosition(int x, int y)
{
	posX = x;
	posY = y;
	sprite->posX = x;
	sprite->posY = y;
}

void Tile::setDimensions(int w, int h)
{
	width = w;
	height = h;
}