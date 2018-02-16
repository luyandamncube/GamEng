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

bool Game::loadmedia()
{
	bool result = true;
	picture = SDL_LoadBMP("srcs/image01.bmp");
	if (picture == NULL)
	{
		printf("Could not load picture!: SDL_Error %s\n", SDL_GetError());
		result = false;
	}
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
		}
	}
}

void Game::gameloop()
{
	//Needs to be != EXIT, and not != false,  because there are other possible gamestates!
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


