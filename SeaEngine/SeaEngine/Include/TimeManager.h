#pragma once
#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <SDL.h>
#include "IObserver.h"

class TimeManager
{
public:
	TimeManager();
	~TimeManager();

	void registerDelayedCallback(Uint32 interval, IObserver* observer);

private:
	static Uint32 notify(Uint32 interval, void* param);
	
};

#endif // !TIME_MANAGER_H