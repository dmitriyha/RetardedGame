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
		virtual void move();
		virtual ~Character();
	protected:
		Texture* texture;//the pointer to the sprite sheet
		SDL_Rect spriteSheetLoc;//where to find the sprite on the sheet 
		SDL_Rect worldLoc;//where the character is in the world
	private:
};

