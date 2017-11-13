#pragma once
#ifndef ACTOR_H
#define ACTOR_H

namespace Sea
{
	class Actor
	{
	public:
		Actor();
		virtual ~Actor();

		int getXpos() const;
		int getYpos() const;
		int getWidth() const;
		int getHeight() const;

	protected:
		int posX;
		int posY;
		int width;
		int height;
	};
}

#endif // !ACTOR_H