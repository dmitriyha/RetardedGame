#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <SDL.h>

class Player : public Character
{
	
	public:
		Player();
		void eventHandler(SDL_Event event);
		bool isMoving();
		void move();
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
