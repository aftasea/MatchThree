#pragma once
#ifndef I_OBSERVER_H
#define I_OBSERVER_H

class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void onNotify() = 0;
};

#endif // !I_OBSERVER_H