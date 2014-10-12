#include "Player.h"

Player::Player(){
	spriteSheetLoc={0,0,50,50};//where the player sprite is on the sprite sheet
	worldLoc={50,50,50,50};//where the player will go on the canvas
}

SDL_Rect Player::getPlayerLocation(){
	return worldLoc;
}

void Player::eventHandler(SDL_Event event){
	if(event.type==SDL_KEYDOWN){//when the key is pressed
		switch(event.key.keysym.sym){
			case SDLK_RIGHT:
				moving=true;
				movement = "right";
				break;

			case SDLK_LEFT:
				moving = true;
				movement = "left";
				break;

			case SDLK_a:
				moving = true;
				movement = "jump";
				break;

		}
	}
	else if(event.type==SDL_KEYUP){//when the key is let go
		switch(event.key.keysym.sym){
			case SDLK_RIGHT:
				moving=false;
				break;

			case SDLK_LEFT:
				moving = false;
				break;

			case SDLK_a:
				moving = false;
				break;
		}
	}
}

bool Player::isMoving(){//the moving flag
	return moving;
}

void Player::move(string movement){//the move method
	//worldLoc.x++;
	if (movement == "right")
	{
		worldLoc.x = worldLoc.x + 2;
	}

	else if (movement == "left")
	{
		worldLoc.x = worldLoc.x - 2;
	}

	else if (movement == "jump")
	{
		//if (collision){
			collision = false;
			gravityVelocity = -5;
			//worldLoc.y = (480 - spriteSheetLoc.h) - 1;
		//}
		
	}

	//worldLoc.y++;
}

Player::~Player()
{
	//dtor
}
