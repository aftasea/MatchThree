#pragma once
#ifndef I_GAME_H
#define I_GAME_H

namespace Sea
{
	class IGame
	{
	public:
		virtual void update() = 0;
	};
}

#endif // !I_GAME_H