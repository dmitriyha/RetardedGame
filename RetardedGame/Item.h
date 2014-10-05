#pragma once

#include <string>
#include "Texture.h"
using namespace std;

class Item
{
	public:
		void setTexturePointer(Texture* _texture);//set the pointer to the texture
		bool isEquipped(); //checks to see if the iyem is equipped
		virtual void renderItem(); //renders item
		virtual ~Item();
	protected:
		Texture* texture; // the pointer to the spritesheet of the item
		bool equipped; // the flag of if the item is equipped or not
		string name;//name of the item
};