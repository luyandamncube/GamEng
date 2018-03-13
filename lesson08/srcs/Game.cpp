/**************************************************
 * File Name : Game.cpp
 * Creation Date : 02-03-2018
 * Last Modified : Tue 13 Mar 2018 04:56:03 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#include "Game.h"
#include "TextureManager.h"
#include <stdio.h>

SDL_Rect srcR, destR;

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
	player1 = TextureManager::loadtexture("img/player.png", renderer);
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
	SDL_RenderCopy(renderer,player1, NULL, &destR);
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
	i++;
	destR.h = 32;
	destR.w = 32;
	destR.x = i;
}

void Game::closeSDL()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL; 
	SDL_DestroyTexture(player1);
	player1 = NULL;
	IMG_Quit();	
	SDL_Quit();
}

void Game::gameloop()
{
	while (currentstate != EXIT)
	{
		/* framestart: how many milliseconds it has been since SDL was initialised
		 * frametime: how long it's taken handle events, update & render
		 */
		framestart = SDL_GetTicks();

		eventhandler();
		update();
		render();

		frametime = SDL_GetTicks() - framestart;
		//Delays our program to provide smoother object movement
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
