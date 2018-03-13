/**************************************************
 * File Name : TextureManager.cpp
 * Creation Date : 08-03-2018
 * Last Modified : Tue 13 Mar 2018 04:55:00 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#include "TextureManager.h"
#include "Game.h" //Need access to variables in Game.h

SDL_Texture *TextureManager::loadtexture(char *path, SDL_Renderer *ren)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path);
	if( loadedSurface == NULL )
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{

		newTexture = SDL_CreateTextureFromSurface(ren, loadedSurface);
		if( newTexture == NULL )
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		SDL_FreeSurface(loadedSurface);
	}
	return (newTexture);
}
