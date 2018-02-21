/**************************************************
 * File Name : Main.cpp
 * Creation Date : 18-02-2018
 * Last Modified : Sun 18 Feb 2018 07:25:10 PM SAST
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
	}
	Game.closeSDL();
	return (0);
}
