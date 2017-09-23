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

void Tile::initSprite(std::string path)
{
	if (sprite == nullptr)
		sprite = new Sprite{ path };
}

void Tile::setPosition(int x, int y)
{
	sprite->posX = x;
	sprite->posY = y;
}