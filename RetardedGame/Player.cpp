#include "Player.h"

Player::Player(){
	spriteSheetLoc={0,0,spriteWidth,spriteHeight};//where the player sprite is on the sprite sheet
	worldLoc = { 50, 50, spriteWidth, spriteHeight };//where the player will go on the canvas
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
		worldLoc.x = worldLoc.x + movementSpeed;
	}

	else if (movement == "left")
	{
		worldLoc.x = worldLoc.x - movementSpeed;
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

void Player::collisionHandler(bool collision){
	if (previousTickCount == 0){
		currentTickCount = SDL_GetTicks();
		previousTickCount = SDL_GetTicks();
	}
	else{
		previousTickCount = currentTickCount;
		currentTickCount = SDL_GetTicks();
	}

	if (collision && invulnTime == 0){
		hit = true;
		lives--;
	}
	else if (invulnTime > 2000){
		hit = false;
		invulnTime = 0;
	}

	if (hit){
		invulnTime += (currentTickCount - previousTickCount);
		flashTime += (currentTickCount - previousTickCount);
		if (flashTime > 200){
			if (spriteSheetLoc.h > 0){
				spriteSheetLoc.h = 0;
				spriteSheetLoc.w = 0;
			}
			else{
				spriteSheetLoc.h = spriteHeight;
				spriteSheetLoc.w = spriteWidth;
			}
			flashTime = 0;
		}
	}
	else{
		flashTime = 0;
		invulnTime = 0;
		spriteSheetLoc = { 0, 0, spriteWidth, spriteHeight };
	}
}

Player::~Player()
{
	//dtor
}
