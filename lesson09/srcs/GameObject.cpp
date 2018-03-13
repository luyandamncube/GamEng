/**************************************************
 * File Name : GameObject.cpp
 * Creation Date : 13-03-2018
 * Last Modified : Tue 13 Mar 2018 07:49:00 PM SAST
 * Created By :		lmncube
 * https://github.com/luyandamncube
 **************************************************/

#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"

GameObject::GameObject(char *texturesheet, SDL_Renderer *ren, int x, int y)
{
	renderer =  ren;
	player1texture = TextureManager::loadtexture(texturesheet,ren);
	xpos = x;
	ypos = y; 
}

void GameObject::update()
{
	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.w * 2;
	destRect.w = srcRect.h * 2;

}

void GameObject::render()
{
	SDL_RenderCopy(renderer, player1texture, &srcRect, &destRect);
}
