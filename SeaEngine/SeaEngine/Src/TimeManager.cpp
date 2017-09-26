#include "TimeManager.h"

TimeManager* TimeManager::instance = nullptr;

TimeManager::TimeManager()
{
	if (instance == nullptr)
		instance = this;
}

TimeManager::~TimeManager()
{}

void TimeManager::update()
{
	while (!observersToNotify.empty())
	{
		observersToNotify.front()->onNotify();
		observersToNotify.pop();
	}
}

void TimeManager::registerDelayedCallback(Uint32 interval, IObserver* observer)
{
	// add callback to list (to be removed on demand or after executed
	SDL_TimerID timerID = SDL_AddTimer(interval, TimeManager::enqueueNotification, reinterpret_cast<void*>(observer));
}

/*** Note: As SDL_AddTimer is asynchronous, the notifications are enqueued 
	to ensure those are sent only on the update state and not in 
	the render state of the game loop									***/
Uint32 TimeManager::enqueueNotification(Uint32 interval, void* observer)
{
	instance->observersToNotify.push(reinterpret_cast<IObserver*>(observer));
	return 0;
}