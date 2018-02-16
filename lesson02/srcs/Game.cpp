/************************************ 
* File Name : Game.cpp
* Creation Date : 13-02-2018
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
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

bool Game::loadmedia()
{
	bool result = true;
	picture = SDL_LoadBMP("img/image01.bmp");
	if (picture == NULL)
	{
		printf("Could not load picture!: SDL_Error %s\n", SDL_GetError());
		result = false;
	}
        else
	{
		SDL_BlitSurface(picture, NULL, surface, NULL);
        	SDL_UpdateWindowSurface(window);
        	SDL_Delay(2000);
		closeSDL();
	}
	return (result);
}

void Game::closeSDL()
{
        SDL_DestroyWindow(window);
        window = NULL;
        SDL_FreeSurface(picture);
        picture = NULL;
        SDL_Quit();
}
