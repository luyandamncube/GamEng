/************************************ 
* File Name : Game.h
* Creation Date : 13-02-2018
* Created By 	: lmncube
* https://github.com/luyandamncube
************************************/

#ifndef GAME_H
# define GAME_H

#include <SDL.h>

class Game
{
	public: 
		Game();
		~Game();
		bool init();
		bool loadmedia();
		void closeSDL();
	
	private:
		SDL_Window  *window;
		SDL_Surface *surface;
		SDL_Surface *picture;
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
};

#endif
