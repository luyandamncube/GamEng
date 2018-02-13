/*This tutorial focused on event handling 
 *We have a main loop called the Game loop
 *On every iteration, events may occur causing an event queue to populate
 *SDL_PollEvent helps remove each of these till the queue is empty
 **/

#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window  *gWindow = NULL;
SDL_Surface *gBackground = NULL;
SDL_Surface *gPicture = NULL;
SDL_Event eHandler;

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
	bool quit = false;

	if (!init())
		printf("Failed to initialise! %s\n");
	else
	{	 if (!loadmedia())
		printf("Failed to load media! %s\n");
		else
		{
		//Main loop, waits for user to exit to execute close();
			while (!quit)
			{
				while (SDL_PollEvent(&eHandler) != 0 )
				{
					if (eHandler.type == SDL_QUIT)
						quit = true;
				}

				SDL_BlitSurface(gPicture, NULL, gBackground, NULL);
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	close();
	
	return (0);
}
