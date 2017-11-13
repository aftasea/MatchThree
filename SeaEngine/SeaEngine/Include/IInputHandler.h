#pragma once
#ifndef I_INPUT_HANDLER_H
#define I_INPUT_HANDLER_H

union SDL_Event;

namespace Sea
{
	class Actor;

	class IInputHandler
	{
	public:
		virtual const Actor* getOwner() const = 0;
		virtual void onMouseDown() = 0;
	};
}

#endif // !I_INPUT_HANDLER_H