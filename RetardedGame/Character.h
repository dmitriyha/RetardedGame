#pragma once

#include <SDL.h>
#include <string>
#include <iostream>
#include <vector>
#include "Texture.h"
#include "CoordinateStruct.h"
using namespace std;

class Character
{
	public:
		Character();
		virtual void render();
		void setTexturePointer(Texture* _texture);
		void setMapPointer(const vector<vector<int>>* _mapArray);
		void gravity();
		virtual void move();
		virtual void collisionHandler(bool collision);
		virtual ~Character();
	protected:
		const vector<vector<int>>* mapArray;
		string name;//name of the character
		int hearts;//amount of hears
		float gravityVelocity = 0;
		const float gravityConstant = 0.2f;
		const int maxGravityVelocity=10;
		bool collision = false;
		Texture* texture;//the pointer to the sprite sheet
		SDL_Rect spriteSheetLoc;//where to find the sprite on the sheet 
		SDL_Rect worldLoc;//where the character is in the world
		SDL_Rect relativeLoc;
		const int movementSpeed = 2;
		CoordinateStruct location{ 0, 0 };
	private:
};

