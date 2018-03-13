/**************************************************
 * File Name : Game.h
 * Creation Date : 08-03-2018
 * Last Modified : Tue 13 Mar 2018 08:09:54 PM SAST
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
		bool loadmedia();
		void run();
		void closeSDL();
	private:
		void gameloop();
		void eventhandler();
		void update();
		void render();
		
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		enum Gamestate{PLAY,EXIT};
		int i = 0;
		const int FPS = 60;	
		const int framedelay = 1000/FPS;
		unsigned int framestart;
		int frametime;

		Gamestate currentstate;
		SDL_Window  *window;
		SDL_Renderer *renderer;
		SDL_Texture *player1texture;
};

#endif
