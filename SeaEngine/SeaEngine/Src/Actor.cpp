#include "Actor.h"

namespace Sea
{
	Actor::Actor()
	{}

	Actor::~Actor()
	{}

	int Actor::getXpos() const
	{
		return posX;
	}

	int Actor::getYpos() const
	{
		return posY;
	}

	int Actor::getWidth() const
	{
		return width;
	}

	int Actor::getHeight() const
	{
		return height;
	}
}
