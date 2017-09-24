#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <vector>

class Settings
{
public:
	int tileXOffset = 64;
	int tileYOffset = 64;
	int boardWidht = 6;
	int boardHeight = 6;
	int boardStartX = 200;
	int boardStartY = 100;
	std::vector<std::string> characters = {
		"res/images/test.png",
		"res/images/test2.png",
		"res/images/test3.png"
	};
};

#endif // !SETTINGS_H