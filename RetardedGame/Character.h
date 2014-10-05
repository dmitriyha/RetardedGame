#pragma once

#include <SDL.h>
#include <string>
#include <iostream>
#include "Texture.h"
using namespace std;

class Character
{
	public:
		void render();
		void setTexturePointer(Texture* _texture);
		void gravity();
		virtual void move();
		virtual ~Character();
	protected:
		string name;//name of the character
		int hearts;//amount of hears
		float gravityVel = 0.0f;
		float gravityConstant = 1;
		Texture* texture;//the pointer to the sprite sheet
		SDL_Rect spriteSheetLoc;//where to find the sprite on the sheet 
		SDL_Rect worldLoc;//where the character is in the world
	private:
};

