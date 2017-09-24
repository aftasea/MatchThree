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
			"res/images/test.png",
			"res/images/test2.png",
			"res/images/test3.png"/*,
			"res/images/test4.png",
			"res/images/test5.png"*/
		};
	}

	int tileXOffset;
	int tileYOffset;
	int boardWidht;
	int boardHeight;
	int boardStartX;
	int boardStartY;
	std::vector<std::string> characters;
};

#endif // !SETTINGS_H