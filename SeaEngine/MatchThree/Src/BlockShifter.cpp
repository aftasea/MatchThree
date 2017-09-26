#include "BlockShifter.h"
#include "Tile.h"
#include "Engine.h"
#include "MatchThree.h"

#include <iostream>

BlockShifter::BlockShifter(int shifts, int32_t intervalDelay, std::vector<Tile*> tilesToShift) :
	remainingShifts(shifts), delay(intervalDelay), tiles(tilesToShift)
{
	shift();
}

BlockShifter::~BlockShifter()
{
}

bool BlockShifter::finished() const
{
	return remainingShifts == 0;
}

void BlockShifter::onNotify()
{
	swapTiles(0, nullptr);
}

void BlockShifter::shift()
{
	if (remainingShifts > 0)
		Engine::getInstance().registerDelayedCallback(delay, this);
		//swapTiles(0, 0);
	else
		; // TODO: unregister callback
		
}

uint32_t BlockShifter::swapTiles(uint32_t interval, void* param)
{
	std::cout << "There are " << tiles.size() << " tiles" << std::endl;
	for (int k = 0; k < tiles.size() - 1; ++k)
	{
		std::cout << "swapping " << k << " and " << (k+1) << std::endl;
		tiles[k]->setSpriteFrom(tiles[k + 1]);
	}

	MatchThree::getInstance().setNewSprite(tiles[tiles.size() - 1]);

	--remainingShifts;
	shift();
	return 0;
}

