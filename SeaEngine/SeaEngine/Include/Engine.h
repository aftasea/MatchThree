#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "IGame.h"

struct SDL_Window;
struct SDL_Surface;

class Engine
{
public:
	Engine() : window(nullptr), screenSurface(nullptr)
	{}

	~Engine();

	void Init(int width, int height, std::string name);
	void Run(IGame &game);

private:
	SDL_Window* window;
	SDL_Surface* screenSurface;
};

#endif // !ENGINE_H