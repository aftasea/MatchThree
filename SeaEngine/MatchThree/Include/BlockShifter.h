#pragma once
#ifndef BLOCK_SHIFTER_H
#define BLOCK_SHIFTER_H

#include <vector>
#include <cstdint>

#include "IObserver.h"

class Tile;

class BlockShifter : IObserver
{
public:
	BlockShifter(int shifts, int32_t intervalDelay, std::vector<Tile*> tilesToShift);
	~BlockShifter();

	bool finished() const;

	void onNotify();

private:
	void shift();
	uint32_t swapTiles(uint32_t interval, void* param);

	int remainingShifts;
	int32_t delay;
	std::vector<Tile*> tiles;
};

#endif // !BLOCK_SHIFTER_H