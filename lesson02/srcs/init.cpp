bool	init(SDL_Surface &gBackground)
{
	bool result = false;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialise! SDL_Error: %s\n", SDL_GetError());
		result = false;
	}
	else
		gWindow = SDL_CreateWindow("SDL Tutorial",  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow = NULL)
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
		result = false;
	}
	else
		gBackground = SDL_GetWindowSurface(gWindow);
	return (result);
}
