#include "Character.h"

void Character::render(){
	SDL_RenderCopy( texture->getRenderer(), texture->getTexture(), &spriteSheetLoc, &worldLoc ); //render the sprite to the canvas
}

void Character::setTexturePointer(Texture* _texture){
	texture=_texture;//set the texture pointer
	
}

void Character::gravity(){
	gravityVelocity = gravityVelocity + gravityConstant;
	if (gravityVelocity > maxGravityVelocity){
		gravityVelocity = maxGravityVelocity;
	}

	if (worldLoc.y >= 480 - spriteSheetLoc.h){
		worldLoc.y = 480 - spriteSheetLoc.h;
		gravityVelocity = 0;
	}

	worldLoc.y = worldLoc.y + gravityVelocity;
}

void Character::move(){//the move method
}

Character::~Character()
{
	//dtor
}