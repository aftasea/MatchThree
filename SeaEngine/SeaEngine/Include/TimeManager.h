#pragma once
#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <queue>
#include <SDL.h>
#include "IObserver.h"

class TimeManager
{
public:
	TimeManager();
	~TimeManager();

	void registerDelayedCallback(Uint32 interval, IObserver* observer);
	void update();

private:
	static TimeManager* instance;

	static Uint32 enqueueNotification(Uint32 interval, void* param);
	std::queue<IObserver*> observersToNotify;
};

#endif // !TIME_MANAGER_H