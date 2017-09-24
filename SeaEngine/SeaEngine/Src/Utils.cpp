#include "Utils.h"

int Utils::getRandom(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}