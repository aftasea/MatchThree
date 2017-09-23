#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <map>
#include <vector>
#include "IGame.h"

struct SDL_Window;
struct SDL_Surface;
struct SDL_Rect;

class Sprite;

class Engine
{
public:
	Engine() : window(nullptr), screenSurface(nullptr), game(nullptr)
	{
		if (Engine::instance == nullptr)
			Engine::instance = this;
	}

	~Engine();

	static Engine& getInstance()
	{
		return (*Engine::instance);
	}

	void init(int width, int height, std::string name);
	void run(IGame &game);

	void registerRenderableObject(Sprite* sprite);

private:
	static Engine* instance;

	void update();
	void render();
	SDL_Surface* loadImage(std::string path);

	SDL_Window* window;
	SDL_Surface* screenSurface;
	IGame* game;

	std::map<std::string, SDL_Surface*> images;
	std::vector<Sprite*> sprites;
};

#endif // !ENGINE_H