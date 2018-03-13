/**************************************************
 * File Name : TextureManager.h
 * Creation Date : 08-03-2018
 * Last Modified : Tue 13 Mar 2018 08:10:29 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#ifndef TEXTUREMANAGER_H
# define TEXTUREMANAGER_H

#include <SDL.h> 

class TextureManager
{
	public:
	static SDL_Texture *loadtexture(char *path, SDL_Renderer *ren);
};

#endif 
