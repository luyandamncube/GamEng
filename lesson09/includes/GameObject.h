/**************************************************
 * File Name : GameObject.h
 * Creation Date : 13-03-2018
 * Last Modified : Tue 13 Mar 2018 08:10:13 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"
/* Game Object class: handles texture, rect and movement of an object
 * Each object also needs to have it's own Update & Render capabilities
 */

class GameObject
{
	public:
		GameObject(char *texturesheet, SDL_Renderer *ren, int x, int y);
		~GameObject();

		void update();
		void render();
	private:
		int xpos;
		int ypos;

		SDL_Texture *player1texture;
		SDL_Rect srcRect, destRect;
		SDL_Renderer *renderer;
};

#endif
