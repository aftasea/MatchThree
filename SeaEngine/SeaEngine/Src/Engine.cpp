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
//SDL_FreeSurface( gHelloWorld );
SDL_Surface* gHelloWorld = nullptr;

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
			gHelloWorld = SDL_LoadBMP("res/images/test.bmp");
			if (gHelloWorld == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "res/images/test.bmp", SDL_GetError());
			}

		}
	}

	/*SDL_DestrroyWindow(window);
	SDL_Quit();*/
}

void Engine::Run(IGame &game)
{
	SDL_Event event;
	bool shouldQuit = false;

	while (!shouldQuit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&event) != 0)
		{
			//User requests quit
			if (event.type == SDL_QUIT)
				shouldQuit = true;
		}

		if (window != nullptr)
		{
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			if (gHelloWorld != nullptr)
				SDL_BlitSurface(gHelloWorld, NULL, screenSurface, NULL);


			SDL_UpdateWindowSurface(window);
			//SDL_Delay(2000);

		}

		game.Update();
		game.Render();
	}
}
