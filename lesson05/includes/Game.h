/**************************************************
 * File Name : Game.h
 * Creation Date : 02-03-2018
 * Last Modified : Fri 02 Mar 2018 10:39:35 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#ifndef GAME_H
# define GAME_H

#include <SDL.h>

class Game
{
	public:
		Game();
		~Game();

		bool init();
		void render();
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
};

#endif
