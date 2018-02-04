#include "SDL.h"
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int	main(int argc, char **argv)
{
	SDL_Window *gWindow = NULL;
	SDL_Surface *gBackground = NULL; 
	if (!init(gBackground))
		printf("SDL could not initialise! SDL_Error: %s\n", SDL_GetError());
	else
	if (!loadMedia())
		printf("Media could not be loaded! SDL_Error: %s\n",SDL_GetError());
	else
	{
		SDL_BlitSurface(gWindow, NULL, gBackground, NULL ); 
		SDL_Delay(2000);
	}

	close_SDL();
	return (0);
}
