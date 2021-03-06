#include "Engine.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "IInputHandler.h"
#include "Actor.h"
#include "TimeManager.h"
#include "IObserver.h"

#include <cstdlib>
#include <ctime>


namespace Sea
{
	Engine::Engine() : window(nullptr), screenSurface(nullptr), game(nullptr), timeManager(nullptr)
	{
		timeManager = new TimeManager();
	}

	Engine::~Engine()
	{
		for (auto imgPair : images)
			SDL_FreeSurface(imgPair.second);
		if (window != nullptr)
			SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Engine::init(int width, int height, std::string name)
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		{
			return;
		}
		else
		{
			int imgFlags = IMG_INIT_PNG;
			IMG_Init(imgFlags);

			window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
			if (window != nullptr)
			{
				screenSurface = SDL_GetWindowSurface(window);
			}
		}

		srand(static_cast<unsigned int>(time(0)));
	}


	void Engine::run(IGame &game)
	{
		this->game = &game;

		SDL_Event event;
		bool shouldQuit = false;

		while (!shouldQuit)
		{
			while (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
					shouldQuit = true;

				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					int x, y;
					SDL_GetMouseState(&x, &y);
					for (IInputHandler* handler : inputHandlers)
					{
						if (isPointInside(handler->getOwner(), x, y))
							handler->onMouseDown();
					}
				}
			}

			update();
			render();
		}
	}

	void Engine::update()
	{
		timeManager->update();
		game->update();
	}

	void Engine::render()
	{
		if (window != nullptr)
		{
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			SDL_Surface* surface = nullptr;
			std::map<std::string, SDL_Surface*>::iterator it;
			SDL_Rect pos;
			for (auto &pair : sprites)
			{
				for (auto sprite : pair.second)
				{
					if (sprite->isVisible)
					{
						it = images.find(sprite->getPath());
						if (it != images.end())
						{
							surface = it->second;
							pos.x = sprite->posX;
							pos.y = sprite->posY;
							SDL_BlitSurface(surface, NULL, screenSurface, &pos);
						}
					}
				}
			}

			SDL_UpdateWindowSurface(window);
		}
	}

	SDL_Surface* Engine::loadImage(std::string path)
	{
		SDL_Surface* optimizedSurface = nullptr;
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == nullptr)
		{
			printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, NULL);
			if (optimizedSurface == nullptr)
			{
				printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			SDL_FreeSurface(loadedSurface);

			Uint32 colorkey = SDL_MapRGB(optimizedSurface->format, 0, 0xFF, 0xFF);
			SDL_SetColorKey(optimizedSurface, SDL_TRUE, colorkey);
		}

		return optimizedSurface;
	}

	void Engine::registerRenderableObject(int layer, Sprite* sprite)
	{
		std::string path = sprite->getPath();
		std::map<std::string, SDL_Surface*>::iterator it = images.find(path);
		if (it == images.end())
		{
			SDL_Surface* image = loadImage(path);
			if (image == nullptr)
				return;

			images[path] = image;
		}

		sprites[layer].push_back(sprite);
	}

	void Engine::unregisterRenderableObject(Sprite* sprite)
	{
		for (auto &pair : sprites)
		{
			auto &sprites = pair.second;
			sprites.erase(std::remove(sprites.begin(), sprites.end(), sprite), sprites.end());
		}
	}

	void Engine::registerInputHandler(IInputHandler* handler)
	{
		inputHandlers.push_back(handler);
	}

	void Engine::registerDelayedCallback(uint32_t interval, IObserver* observer)
	{
		timeManager->registerDelayedCallback(interval, observer);
	}

	bool Engine::isPointInside(const Actor* actor, int pointX, int pointY) const
	{
		if (pointX < actor->getXpos())
			return false;

		if (pointX > actor->getXpos() + actor->getWidth())
			return false;

		if (pointY < actor->getYpos())
			return false;

		if (pointY > actor->getYpos() + actor->getHeight())
			return false;

		return true;
	}
}