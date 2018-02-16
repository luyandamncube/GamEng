/************************************ 
* File Name : Game.cpp
* Creation Date : 13-02-2018
* Created By 	: lmncube
* https://github.com/luyandamncube
************************************/

#include "Game.h"
#include <stdio.h>
//#include <GL.h> for when we provide openGL support

Game::Game()
{
	//use nullptr, NULL is depracated in C++
	window = nullptr;
	surface = nullptr;
}

Game::~Game()
{
}

bool Game::init()
{
	bool result = true;
	//Standard practice to open all init subsystems instead of just video
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialise! SDL_Error: %s\n", SDL_GetError());
		result = false;
	}
	else
	{
		//SDL_WINDOWPOS_CENTERED is also standard
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			result = false;
		}
		else
		{
			surface = SDL_GetWindowSurface(window);
			//Fills surface with white using 0xFF hex value
			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	return (result);
}
