#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <string>

namespace Sea
{
	class Sprite
	{
	public:
		Sprite(int layer, std::string filepath);
		~Sprite();

		const std::string& getPath() const;
		int getId() const;

		int posX;
		int posY;
		bool isVisible;

		friend bool operator== (const Sprite &s1, const Sprite &s2);

	private:
		std::string path;
		int id;
	};
}

#endif // !SPRITE_H