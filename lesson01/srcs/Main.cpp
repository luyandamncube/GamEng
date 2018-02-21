/**************************************************
 * File Name : Main.cpp
 * Creation Date : 13-02-2018
 * Last Modified : Wed 21 Feb 2018 10:52:39 AM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#include "Game.h"

int main(int argc, char **argv)
{
	Game Game;
	if (!Game.init())
		printf("Failed to initialise!\n");
	return (0);
}
