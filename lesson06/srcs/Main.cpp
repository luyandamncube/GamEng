/**************************************************
 * File Name : Main.cpp
 * Creation Date : 02-03-2018
 * Last Modified : Thu 08 Mar 2018 12:00:32 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#include "Game.h"

int main(int argc, char **argv)
{
	Game Game;
	if (!Game.init())
		printf("Failed to initialise!\n");
	else
	{
		if (!Game.loadmedia())
			printf("Failed to load media!\n");
		else
		Game.run();
	}
	Game.closeSDL();
	return (0);
}
