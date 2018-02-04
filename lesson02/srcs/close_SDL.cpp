close_SDL() 
{ 
	SDL_FreeSurface( gBackground ); 
	gHelloWorld = NULL; 
	SDL_DestroyWindow( gWindow ); 
	gWindow = NULL; 
	SDL_Quit(); 
}
