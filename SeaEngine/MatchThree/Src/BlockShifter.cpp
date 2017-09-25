#include "BlockShifter.h"
#include "Tile.h"
#include "Engine.h"

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
	else
		; // TODO: unregister callback
		
}

uint32_t BlockShifter::swapTiles(uint32_t interval, void* param)
{
	for (int k = 0; k < tiles.size() - 1; ++k)
	{
		tiles[k]->swapSprite(tiles[k + 1]);
	}

	--remainingShifts;
	shift();
	return 0;
}

