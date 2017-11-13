#include "Utils.h"

namespace Sea
{
	int Utils::id = 0;

	int Utils::getRandom(int min, int max)
	{
		return (rand() % (max - min + 1)) + min;
	}

	int Utils::getNewId()
	{
		return id++;
	}
}