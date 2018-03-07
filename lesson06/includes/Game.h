/**************************************************
 * File Name : Game.h
 * Creation Date : 02-03-2018
 * Last Modified : Sat 03 Mar 2018 12:38:14 AM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#ifndef GAME_H
# define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game
{
	public:
		Game();
		~Game();

		bool init();
		void render();
		bool loadmedia();
		void run();
		void closeSDL();

	private:
		void gameloop();
		void eventhandler();
		//Handles on-screen changes i.e. movement of objects
		void update();

		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		enum Gamestate{PLAY,EXIT};

		Gamestate currentstate;
		SDL_Window  *window;
		//changed display medthod to SDL_renderer, SDL_Surface is depracted
		SDL_Renderer *renderer;
		SDL_Surface *surface;
		SDL_Texture *player1;
		SDL_Surface *loadsurface(char *path);

};

#endif
