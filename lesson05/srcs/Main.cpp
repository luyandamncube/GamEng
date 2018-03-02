/**************************************************
 * File Name : Main.cpp
 * Creation Date : 02-03-2018
 * Last Modified : Fri 02 Mar 2018 10:16:28 PM SAST
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
		Game.run();
	}
	Game.closeSDL();
	return (0);
}
