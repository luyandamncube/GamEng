/*This tutorial uses event handling to change the on screen image depending on the keys the user presses
 * Use an enum structure as it indexes entries starting at 0 by default
 * Use gCurrent to hold each surface created by user key press
 * */

#include <SDL.h>
#include <string>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum KeyPressSurfaces 
{ 
	KEY_PRESS_SURFACE_DEFAULT, 
	KEY_PRESS_SURFACE_UP, 
	KEY_PRESS_SURFACE_DOWN, 
	KEY_PRESS_SURFACE_LEFT, 
	KEY_PRESS_SURFACE_RIGHT, 
	KEY_PRESS_SURFACE_TOTAL 
};

SDL_Window  *gWindow = NULL;
SDL_Surface *gBackground = NULL;
SDL_Surface *gCurrent = NULL;
SDL_Surface *loadSurface(std::string path); 
SDL_Surface *gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

bool init();
bool loadMedia();
void close();

bool init() 
{
	bool result = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Could not initialise! SDL_Error: %s\n", SDL_GetError());
		result = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("SDL Key Press Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Could not create window! SDL_Error: %s\n", SDL_GetError());
			result = false;
		}
		else 
			gBackground = SDL_GetWindowSurface(gWindow);
	}
	return (result);
}

SDL_Surface	*loadsurface(std::string path)
{
	//c_str() converts path to a c-style string, ie char *str
	SDL_Surface *temp = SDL_LoadBMP(path.c_str());
	if (temp == NULL)
	{
		printf("Could not load media! SDL_Error: %s\n", SDL_GetError());
	}
	else
		return (temp);
	
}

bool loadMedia()
{
	bool result = true;
	
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadsurface("srcs/keypress_default.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Failed to load image! %s\n");
		result = false;
	}
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadsurface("srcs/keypress_up.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Failed to load image! %s\n");
		result = false;
	}
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadsurface("srcs/keypress_down.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		printf("Failed to load image! %s\n");
		result = false;
	}
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadsurface("srcs/keypress_left.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("Failed to load image! %s\n");
		result = false;
	}
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadsurface("srcs/keypress_right.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("Failed to load image! %s\n");
		result = false;
	}
	return (result);

}

void close()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_FreeSurface(gBackground);
	gBackground = NULL;
}

int	main(int argc, char **argv)
{
	bool quit = false;

	SDL_Event eHandler;

	if (!init())
		printf("Failed to initialise! %s\n");
	else if (loadMedia() == false)
		printf("Failed to load media! %s\n");
	else
	{
		while (!quit)
		{
			while (SDL_PollEvent(&eHandler))
			{
				if (eHandler.type == SDL_QUIT)
					quit = true;
				else if (eHandler.type == SDL_KEYDOWN)
				{
					switch(eHandler.key.keysym.sym)
				 	{ 
						case SDLK_UP: 
						gCurrent = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP]; 
						break; 
						case SDLK_DOWN: 
						gCurrent = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN]; 
						break; 
						case SDLK_LEFT: 
						gCurrent = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT]; 
						break; 
						case SDLK_RIGHT: 
						gCurrent = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT]; 
				 		break; 
						default: 
						gCurrent = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT]; 
						break; 
				 	}
				}	
			}	
			SDL_BlitSurface(gCurrent, NULL, gBackground, NULL);
			SDL_UpdateWindowSurface(gWindow);
		}
	}
	close();
}
