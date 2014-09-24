#include "Player.h"

Player::Player(){
	spriteSheetLoc={0,0,50,50};//where the player sprite is on the sprite sheet
	worldLoc={0,0,50,50};//where the player will go on the canvas
}

void Player::eventHandler(SDL_Event event){
	if(event.type==SDL_KEYDOWN){//when the key is pressed
		switch(event.key.keysym.sym){
			case SDLK_w:
				moving=true;
				break;
		}
	}
	else if(event.type==SDL_KEYUP){//when the key is let go
		switch(event.key.keysym.sym){
			case SDLK_w:
				moving=false;
				break;
		}
	}
	
	
}

bool Player::isMoving(){//the moving flag
	return moving;
}

void Player::move(){//the move method
	worldLoc.x++;
	worldLoc.y++;
}

Player::~Player()
{
	//dtor
}
