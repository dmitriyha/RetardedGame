#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Weapon.h"
#include <SDL.h>
#include "Map.h"
#include "MapStructure.h"


class Player : public Character
{
	
	public:
		Player();
		SDL_Rect getPlayerLocation();
		void eventHandler(SDL_Event event);
		bool isMoving();
		string movement;
		void move(string direction);		
		~Player();
	protected:
	private:
		int w=0;
		bool moving;
		int lives;//amount of lives (not hears)
		int continues;//amount of continues (usually like... 3 or 2?)
		int cookies;//amount of collected cookies
		Weapon weapon;//weapon being used at the moment
		string position;//what's the position, for example: looking up, idle, duck etc...
};

#endif // PLAYER_H
