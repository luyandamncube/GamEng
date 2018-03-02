/**************************************************
 * File Name : Game.cpp
 * Creation Date : 02-03-2018
 * Last Modified : Fri 02 Mar 2018 10:31:04 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#include "Game.h"
#include <stdio.h>

Game::Game()
{
	window = nullptr;
	renderer = nullptr;
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
			renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
		{
			printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
			result = false; 
		}
		//Sets renderer buffer to white
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		//Remember your blitting issues in lesson04. Its better to start your render once you have dealt with your SDL variables
		render();
	}
	return (result);
}

void Game::render()
{
	//Clear up render buffer
	SDL_RenderClear(renderer);
	//Place to start rendering objects
	SDL_RenderPresent(renderer);

}

void Game::eventhandler()
{
	SDL_Event eHandler;
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

//Handles movement/game logic. For now
void Game::update()
{
	int i = 0;
	i++;
	//printf("%d",i);
}

void Game::closeSDL()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL; 
	SDL_Quit();
}

void Game::gameloop()
{
	while (currentstate != EXIT)
	{
		update();
		eventhandler();
	}
}

void Game::run()
{
	gameloop();
}

