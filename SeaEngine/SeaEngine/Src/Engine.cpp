#include "Engine.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

#include <cstdlib>
#include <ctime>


Engine* Engine::instance = nullptr;

/*
Engine::Engine()
{
}*/

Engine::~Engine()
{
}

//TODO: Free method for releasing resources (hint: use mart pointers)
//SDL_FreeSurface( gHelloWorld );

void Engine::init(int width, int height, std::string name)
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return;
	}
	else
	{
		int imgFlags = IMG_INIT_PNG;
		IMG_Init(imgFlags);
		//if (!(IMG_Init(imgFlags) & imgFlags))

		window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (window != nullptr)
		{
			screenSurface = SDL_GetWindowSurface(window);
			//gHelloWorld = loadImage("res/images/test.png");
		}
	}

	/*SDL_DestrroyWindow(window);
	SDL_Quit();*/

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
		}
		
		update();
		render();
	}
}

void Engine::update()
{
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
		for (auto &sprite : sprites)
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
		/*if (gHelloWorld != nullptr)
			SDL_BlitSurface(gHelloWorld, NULL, screenSurface, nullptr);*/


		game->render();

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

		Uint32 colorkey = SDL_MapRGB(optimizedSurface->format, 0, 0x00, 0x00);
		SDL_SetColorKey(optimizedSurface, SDL_TRUE, colorkey);
	}

	return optimizedSurface;
}

void Engine::registerRenderableObject(Sprite* sprite)
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

	sprites.push_back(sprite);
}
