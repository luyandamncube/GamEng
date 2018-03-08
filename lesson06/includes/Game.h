/**************************************************
 * File Name : Game.h
 * Creation Date : 02-03-2018
 * Last Modified : Thu 08 Mar 2018 01:48:40 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#ifndef GAME_H
# define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//SDL_Rect srcR, destR;

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
		//Handles on-screen changes i.e. movement of objects
		void update();
		//Handles our object rendering
		void render();
		
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		enum Gamestate{PLAY,EXIT};

		Gamestate currentstate;
		SDL_Window  *window;
		//changed display method to rendering, blitting images raw uses too many resources
		SDL_Renderer *renderer;
		SDL_Texture *player1;
		SDL_Texture *loadtexture(char *path);

};

#endif
