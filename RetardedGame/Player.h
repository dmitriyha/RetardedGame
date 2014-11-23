#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Weapon.h"
#include <SDL.h>
#include <vector>
#include "Map.h"
#include "MapStructure.h"

class Player : public Character
{
	
	public:
		Player();
		SDL_Rect getPlayerLocation();
		void render();
		void eventHandler(SDL_Event event);
		bool isMoving();
		string movement;
		void move(string direction);
		void collisionHandler(bool collision);
		~Player();
	protected:
	private:
		bool moving;
		int lives=2;//amount of lives (not hears)
		int continues;//amount of continues (usually like... 3 or 2?)
		int cookies;//amount of collected cookies
		Weapon weapon;//weapon being used at the moment
		string position;//what's the position, for example: looking up, idle, duck etc...

		const int spriteWidth = 40;//the width of the sprite
		const int spriteHeight = 58;//the height of the sprite

		int currentTickCount=0;//the timer ticks
		int previousTickCount=0;//the previous tick count
		int flashTime = 0;//time ellapsed since last flash
		int invulnTime = 0; //time passed since las collision

		int animationTimer = 0;
		int frame = 0;
		int frame_walk = 18;

		bool hit = false;//if the player is hit, makes hime flash

		bool ducking = false;
		bool wasDucking = false;

		vector <SDL_Rect> rectList;

		SDL_Rect duckStart;
		SDL_Rect duck;
		SDL_Rect duckBlink;

		SDL_Rect walk;
		
};

#endif // PLAYER_H
