#include "Engine.h"
#include <SDL.h>
/*
Engine::Engine()
{
}*/

Engine::~Engine()
{
}

//TODO: Free method for releasing resources (hint: use mart pointers)

void Engine::Init(int width, int height, std::string name)
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return;
	}
	else
	{
		window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (window != nullptr)
		{
			screenSurface = SDL_GetWindowSurface(window);
		}
	}

	/*SDL_DestroyWindow(window);
	SDL_Quit();*/
}

void Engine::Run(IGame &game)
{
	while (true)
	{
		if (window != nullptr)
		{
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			//SDL_Delay(2000);
		}

		game.Update();
		game.Render();
	}
}
