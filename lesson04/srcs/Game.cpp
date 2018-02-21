/************************************ 
* File Name : Game.cpp
* Creation Date : 16-02-2018
* Created By 	: lmncube
* https://github.com/luyandamncube
************************************/

#include "Game.h"
#include <stdio.h>

Game::Game()
{
	window = nullptr;
	surface = nullptr;
	picture = nullptr;
	currentstate = PLAY;
}

Game::~Game()
{
}

bool Game::init()
{
	bool result = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialise! SDL_Error: %s\n", SDL_GetError());
		result = false;
	}
	else
	{
		window = SDL_CreateWindow("SDL Event Handler Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			result = false; 
		}
                else 
                        surface = SDL_GetWindowSurface(window);
	}
	return (result);
}

//Function to return a pointer to surface
SDL_Surface	*Game::loadsurface(char *path)
{
	SDL_Surface *temp = SDL_LoadBMP(path);
	if (temp == NULL)
		printf("Could not load media! SDL_Error: %s\n", SDL_GetError());
	else
		return (temp);
}

void Game::loadimages (int keypress, char *path)
{
	arrsurface[keypress] = loadsurface(path);
	if (arrsurface[keypress] == NULL)
		printf("Failed to load images to surfaces! %s\n");
}

bool Game::loadmedia()
{
	bool result = true;
	loadimages(KEY_DEFAULT, "img/keypress_default.bmp");
	loadimages(KEY_UP, "img/keypress_up.bmp");
	loadimages(KEY_DOWN, "img/keypress_down.bmp");
	loadimages(KEY_LEFT, "img/keypress_left.bmp");
	loadimages(KEY_RIGHT, "img/keypress_right.bmp");
	return (result);
}

void Game::closeSDL()
{
        SDL_FreeSurface(picture);
        picture = NULL;
        SDL_DestroyWindow(window);
        window = NULL;
        SDL_Quit();
}

void Game::processInput()
{
	// Create a union data type
	SDL_Event eHandler;
	//Event Handler loop. Now allows window to accept input
	while (SDL_PollEvent(&eHandler))
	{
		switch(eHandler.type)
		{
			case SDL_QUIT:
				currentstate = EXIT;
				break;
			case SDL_KEYDOWN:
				switch(eHandler.key.keysym.sym)
				{
					case SDLK_UP:
					current = arrsurface[KEY_UP];
					break;

					case SDLK_DOWN:
					current = arrsurface[KEY_DOWN];
					break;

					case SDLK_LEFT:
					current = arrsurface[KEY_LEFT];
					break;

					case SDLK_RIGHT:
					current = arrsurface[KEY_RIGHT];
					break;

					default:
					current = arrsurface[KEY_DEFAULT];
					break;
				}
				break;
		}
		SDL_BlitSurface(current, NULL, surface, NULL);
		SDL_UpdateWindowSurface(window);
	}
}

void Game::gameloop()
{
	SDL_BlitSurface(arrsurface[KEY_DEFAULT], NULL, surface, NULL);
	SDL_UpdateWindowSurface(window);
	while (currentstate != EXIT)
	{
		processInput();
	
        	SDL_BlitSurface(picture, NULL, surface, NULL);
        	SDL_UpdateWindowSurface(window);
	}
}

void Game::run()
{
	gameloop();
}
