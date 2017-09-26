#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <vector>

class Settings
{
public:
	Settings()
	{
		tileXOffset = 64;
		tileYOffset = 64;
		
		boardWidht = 6;
		boardHeight = 6;
		boardStartX = 200;
		boardStartY = 100;

		characters = {
			"res/images/jelly_1.png",
			"res/images/jelly_2.png",
			"res/images/jelly_3.png",
			"res/images/jelly_4.png",
			"res/images/jelly_5.png"/*,
			"res/images/jelly_6.png"*/
		};

		clearedSprite = "res/images/test.png";
	}

	int tileXOffset;
	int tileYOffset;
	int boardWidht;
	int boardHeight;
	int boardStartX;
	int boardStartY;
	std::vector<std::string> characters;
	std::string clearedSprite;
};

#endif // !SETTINGS_H