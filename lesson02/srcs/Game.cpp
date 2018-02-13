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
	window = nullptr;
	surface = nullptr;
	picture = nullptr;
}

Game::~Game()
{
}

//Function to load an image with the path as a parameter. Returns a pointer to the new surface
void Game::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		printf("SDL could not initialise! SDL_Error: %s\n", SDL_GetError());
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
                else 
                        surface = SDL_GetWindowSurface(window);
	}
}

void Game::run()
{
	init();
}

void Game::loadmedia()
{
	picture = SDL_LoadBMP("srcs/image01.bmp");
	if (picture == NULL)
		printf("Could not load picture!: SDL_Error %s\n", SDL_GetError());
        else
	{
		//Blit/Copy source image to destination
		SDL_BlitSurface(picture, NULL, surface, NULL);
        	SDL_UpdateWindowSurface(window);
        	SDL_Delay(2000);
		closeSDL();
	}

}

//Overload function name close() for the purposes of this project
void Game::closeSDL()
{
        SDL_DestroyWindow(window);
        window = NULL;
        SDL_FreeSurface(picture);
        picture = NULL;
        SDL_Quit();
}

