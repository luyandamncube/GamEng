/**************************************************
 * File Name : Game.cpp
 * Creation Date : 02-03-2018
 * Last Modified : Thu 08 Mar 2018 02:34:24 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#include "Game.h"
#include <stdio.h>

/*SDL_Rect is a simple sturct SDL_Rect destR = {x,y,h,w}
 * Usage destR.x = 0
 * This should all be done in an object class, we are making it global for demonstrative purposes 
 */

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
			/* Create 2D rendering context for our window (window, index, flags)
			 * index: index of rendering driver. -1 initialises the first one
			 * flags: four different flags or 0 for none. SDL_RENDERER_ACCELERATED lets renderer use hardware acceleration
			 * we can use multiple flags in this parameter using "|", (ex. SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) 
			 */
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
	player1 = loadtexture( "img/player.png" );
	if(player1 == NULL ) 
	{ 
		printf( "Failed to load texture image!\n" );
		result = false; 
	} 
	return (result); 
}

void Game::render()
{
	
	//Clear render buffer
	SDL_RenderClear(renderer);

	/* Painter's Algorithm: load background -> load textures -> load objects
	 * RenderCopy: render a texture to screen (renderer, texture, how much of image to draw, how much of frame to fill)
	 * 1st NULL draws entire image, 2nd NULL draws to entire frame
	 */

	//Render Texture to screen
	SDL_RenderCopy(renderer,player1, NULL, &destR);
	//Update screen with any rendering performed in last screen
	SDL_RenderPresent(renderer);

}

SDL_Texture *Game::loadtexture(char *path) 
{
	SDL_Texture* newTexture = NULL; 

	SDL_Surface* loadedSurface = IMG_Load(path); 
	if( loadedSurface == NULL )
	{ 
		printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
	} 
	else 
	{ 

		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface); 
		if( newTexture == NULL ) 
		{ 
			printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
		} 

		SDL_FreeSurface(loadedSurface);
	} 
	return (newTexture); 
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
	//int i = 0;
	//i++;
	//Use this rectangle and it's dimensions in the RenderCopy function
	destR.h = 32;
	destR.w = 32;
}

void Game::closeSDL()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL; 
	SDL_DestroyTexture(player1);
	player1 = NULL;
	//Quit SDL subsystems
	IMG_Quit();	
	SDL_Quit();
}

void Game::gameloop()
{
	while (currentstate != EXIT)
	{
		eventhandler();
		//Update follows events
		update();
		render();
	}
}

void Game::run()
{
	gameloop();
}
