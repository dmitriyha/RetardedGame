#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <typeinfo>
#include "Texture.h"
using namespace std;

class Character
{
	
	public:
		void render();
		void setTexturePointer(Texture* _texture);
		virtual ~Character();
	protected:
		Texture* texture;//the pointer to the sprite sheet
		SDL_Rect spriteSheetLoc;//where to find the sprite on the sheet 
		SDL_Rect worldLoc;//where the character is in the world
	private:
};

#endif // CHARACTER_H
