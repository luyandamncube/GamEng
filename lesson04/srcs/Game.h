/************************************ 
* File Name : Game.h
* Creation Date : 13-02-2018
* Created By 	: lmncube
* https://github.com/luyandamncube
************************************/

#ifndef GAME_H
# define GAME_H

#include <SDL.h>

//Enum variable where EXIT == 0 and PLAY == 1
class Game
{
	public: 
		Game();
		~Game();
	
		bool init();
		void loadimages(int keypress, char *path);
		bool loadmedia();
		void run();
		void closeSDL();

	private:
		void gameloop();
		void processInput();
	
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		enum Keypress{KEY_DEFAULT, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_TOTAL};
		enum Gamestate{PLAY,EXIT};

		Gamestate currentstate;
		SDL_Window  *window;
		SDL_Surface *surface;
		SDL_Surface *picture;
		SDL_Surface *current;
		SDL_Surface *loadsurface(char *path);
		SDL_Surface *arrsurface[KEY_TOTAL];
};

#endif
