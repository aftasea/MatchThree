#include "Tile.h"
#include "Sprite.h"
#include "Engine.h"
#include <iostream>

Tile* Tile::previousSelected(nullptr);
Sprite* Tile::selectedSprite(nullptr);

Tile::Tile() : sprite(nullptr), isSelected(false)
{
	Engine::getInstance().registerInputHandler(this);

	if (selectedSprite == nullptr)
	{
		selectedSprite = new Sprite(2, "res/images/selected.png");
		selectedSprite->isVisible = false;
	}
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
	if (isSelected)
	{
		deselect();
	}
	else
	{
		if (previousSelected == nullptr)
		{
			select();
		}
		else
		{
			swapSprite(previousSelected);
			previousSelected->deselect();
		}
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
		sprite = new Sprite{ 1, path };
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

void Tile::select()
{
	isSelected = true;
	selectedSprite->posX = posX;
	selectedSprite->posY = posY;
	selectedSprite->isVisible = true;
	previousSelected = this;
}

void Tile::deselect()
{
	isSelected = false;
	selectedSprite->isVisible = false;
	previousSelected = nullptr;
}

void Tile::swapSprite(Tile* newTile)
{
	if (newTile->id == id)
		return;
	std::cout << "swapping " << id << " x " << newTile->id << std::endl;

	int tempId = newTile->id;
	newTile->id = id;
	id = tempId;

	Sprite* tempSprite = newTile->sprite;
	newTile->sprite = sprite;
	newTile->sprite->posX = tempSprite->posX;
	newTile->sprite->posY = tempSprite->posY;
	this->sprite = tempSprite;
	this->sprite->posX = posX;
	this->sprite->posY = posY;
}