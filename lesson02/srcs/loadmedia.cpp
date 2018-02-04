bool loadMedia() 
{ 
	bool result = true;
	gBackground = SDL_LoadBMP( "02_getting_an_image_on_the_screen/hello_world.bmp" ); 
	if( gBackground == NULL ) 
	{ 
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
	       	success = false; 
	} 
	return result; 
}
