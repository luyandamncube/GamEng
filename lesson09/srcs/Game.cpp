/**************************************************
 * File Name : Game.cpp
 * Creation Date : 02-03-2018
 * Last Modified : Tue 13 Mar 2018 08:07:37 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include <stdio.h>

GameObject *player1;
GameObject *player2;

Game::Game()
{
	window = nullptr;
	renderer = nullptr;
	player1 = nullptr;
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
		window = SDL_CreateWindow("SDL Textures Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			result = false; 
		}
		else
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL)
		{
			printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
			result = false; 
		}
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		int imgFlags = IMG_INIT_PNG; 
		if(!( IMG_Init( imgFlags ) & imgFlags ) ) 
		{ 
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError()); 
			result = false; 
		}

	}
	return (result);
}

bool Game::loadmedia() 
{ 
	bool result = true;
	//Create Two player objects
	player1 = new GameObject("img/player1.png",renderer,0,0);
	player2 = new GameObject("img/player2.png",renderer,64,64);
	if(player1 == NULL ) 
	{ 
		printf( "Failed to load texture image!\n" );
		result = false; 
	} 
	return (result); 
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player1->render();
	player2->render();
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

void Game::update()
{
	player1->update(); 
	player2->update(); 
}

void Game::closeSDL()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL; 
	IMG_Quit();	
	SDL_Quit();
}

void Game::gameloop()
{
	while (currentstate != EXIT)
	{
		framestart = SDL_GetTicks();

		eventhandler();
		update();
		render();

		frametime = SDL_GetTicks() - framestart;
		if (framedelay > frametime)
		{
			SDL_Delay(framedelay-frametime);
		}
	}
}

void Game::run()
{
	gameloop();
}
