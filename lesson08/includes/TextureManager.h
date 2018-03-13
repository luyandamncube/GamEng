/**************************************************
 * File Name : TextureManager.h
 * Creation Date : 08-03-2018
 * Last Modified : Thu 08 Mar 2018 08:32:03 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#ifndef TEXTUREMANAGER_H
# define TEXTUREMANAGER_H

#include <SDL.h> //Need to access SDL subsystems

class TextureManager
{
	public:
	static SDL_Texture *loadtexture(char *path, SDL_Renderer *ren);
};

#endif 
