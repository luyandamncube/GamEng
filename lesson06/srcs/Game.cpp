/**************************************************
 * File Name : Game.cpp
 * Creation Date : 02-03-2018
 * Last Modified : Wed 07 Mar 2018 08:28:19 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#include "Game.h"
#include <stdio.h>

Game::Game()
{
	window = nullptr;
	renderer = nullptr;
	surface = nullptr;
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
			renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
		{
			printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
			result = false; 
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		surface = loadsurface("img/player.png");
		if (surface == NULL)
		{
			printf("Could not load image from file! %s\n");
			result = false;
		}
		else 
		/*This HAS to be done in our init step. 
		 * SDL_CreatTex needs direct access to it's paramters renderer and surface after they have both been initialised
		*/
		player1 = SDL_CreateTextureFromSurface(renderer,surface);
		if (player1 == NULL)
		{
			printf("Could not create texture! %s\n");
			result = false;
		}
		else
		render();
	}
	return (result);
}

void Game::render()
{
	//Clear render buffer
	SDL_RenderClear(renderer);
	//Remember to load render objects in painters order (i.e. background first, then tilemaps, then player surfaces)
	//RenderCopy(render to use, texture to render, source of rect to draw, where you want it drawn on screen)
	//1st NULL draws entire image, 2nd NULL draws to entire frame
	SDL_RenderCopy(renderer,player1, NULL, NULL);
	SDL_RenderPresent(renderer);

}

SDL_Surface     *Game::loadsurface(char *path)
{
	//Use IMGload instead of SDL_loadBMP for png images
	SDL_Surface *temp = IMG_Load(path);
	if (temp == NULL)
		printf("Could not load media! SDL_Error: %s\n", SDL_GetError());
	else
		return (temp);
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
}

void Game::closeSDL()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL; 
	SDL_FreeSurface(surface);
	surface = NULL; 
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

