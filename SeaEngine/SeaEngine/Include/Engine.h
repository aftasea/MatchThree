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
	Engine() : window(nullptr), screenSurface(nullptr), game(nullptr)
	{}

	~Engine();

	void init(int width, int height, std::string name);
	void run(IGame &game);

private:
	void update();
	void render();
	SDL_Surface* loadImage(std::string path);

	SDL_Window* window;
	SDL_Surface* screenSurface;
	IGame* game;
};

#endif // !ENGINE_H