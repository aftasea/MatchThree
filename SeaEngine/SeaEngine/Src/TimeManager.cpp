#include "TimeManager.h"

TimeManager::TimeManager()
{
}

TimeManager::~TimeManager()
{}

void TimeManager::registerDelayedCallback(Uint32 interval, IObserver* observer)
{
	// add callback to list (to be removed on demand or after executed
	SDL_TimerID timerID = SDL_AddTimer(interval, TimeManager::notify, reinterpret_cast<void*>(observer));
}

Uint32 TimeManager::notify(Uint32 interval, void* observer)
{
	reinterpret_cast<IObserver*>(observer)->onNotify();
	return 0;
}