#ifndef PLAYER_H
#define PLAYER_H

#include <Character.h>


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
};

#endif // PLAYER_H
