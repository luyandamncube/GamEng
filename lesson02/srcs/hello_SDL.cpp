/*This tutorial focused on making modular functions 
 *SDL_BlitSurface lets us copy a source surface onto a destination surface
 *Remember to only call SDL_UpdateScreen surface after ALL blits for the currrent frame are done 
 * */

#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window  *gWindow = NULL;
SDL_Surface *gBackground = NULL;
SDL_Surface *gPicture = NULL;

bool init();
bool loadmedia();
void close();

bool 	init()
{
	bool result = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Could not initialise!: SDL_Error %s\n", SDL_GetError());
		result = false;
	}	
	else
	{
		gWindow = SDL_CreateWindow("SDL Load image tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Could not create window!: SDL_Error %s\n", SDL_GetError());
			result = false;
		}
		else
			gBackground = SDL_GetWindowSurface(gWindow);		
	}	
	return (result);
}

bool	loadmedia()
{
	bool result = true;
	gPicture = SDL_LoadBMP("srcs/image01.bmp");
	if (gPicture == NULL)
	{
		printf("Could not create window!: SDL_Error %s\n", SDL_GetError());
		result = false;
	}
	return (result);
}

void	close()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_FreeSurface(gPicture);
	gPicture = NULL;
	SDL_Quit();
}

int	main(int argc, char **argv)
{
	if (!init())
		printf("Failed to initialise! %s\n");
	else if (!loadmedia)
		printf("Failed to load media! %s\n");
	else
	{
		//Blit src to dst, ie copy source image to destination
		SDL_BlitSurface(gPicture, NULL, gBackground, NULL);
		SDL_UpdateWindowSurface(gWindow);
		SDL_Delay(2000);
		close();
	}
}
