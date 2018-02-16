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
/*enum class Gamestate
{
	PLAY,
	EXIT
};
*/
class Game
{
	public: 
		Game();
		~Game();
	
		//Public because init & load are dual purpose, they complete a function and give error feedback	
		bool init();
		bool loadmedia();
		void run();
		void closeSDL();

	private:
		void gameloop();
		void processInput();
	
		SDL_Window  *window;
		SDL_Surface *surface;
		SDL_Surface *picture;
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		enum Gamestate{PLAY,EXIT};
		Gamestate currentstate;
};

#endif
