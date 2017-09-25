#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <map>
#include <vector>
#include <cstdint>
#include "IGame.h"
#include "IObserver.h"

struct SDL_Window;
struct SDL_Surface;
struct SDL_Rect;

class Sprite;
class IInputHandler;
class Actor;
class TimeManager;

class Engine
{
public:
	Engine();
	~Engine();

	static Engine& getInstance()
	{
		return (*Engine::instance);
	}

	void init(int width, int height, std::string name);
	void run(IGame &game);

	void registerRenderableObject(int layer, Sprite* sprite);
	void unregisterRenderableObject(Sprite* sprite);
	void registerInputHandler(IInputHandler* handler);
	void registerDelayedCallback(uint32_t interval, IObserver* observer);

private:
	static Engine* instance;

	void update();
	void render();
	SDL_Surface* loadImage(std::string path);
	bool isPointInside(const Actor* actor, int pointX, int pointY) const;

	SDL_Window* window;
	SDL_Surface* screenSurface;
	IGame* game;

	TimeManager* timeManager;

	std::map<std::string, SDL_Surface*> images;
	std::map<int, std::vector<Sprite*>> sprites;
	std::vector<IInputHandler*> inputHandlers;
};

#endif // !ENGINE_H