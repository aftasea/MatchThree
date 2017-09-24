#include "Tile.h"
#include "Sprite.h"

Tile::~Tile()
{
	if (sprite != nullptr)
	{
		delete sprite;
		sprite = nullptr;
	}
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
	sprite->posX = x;
	sprite->posY = y;
}