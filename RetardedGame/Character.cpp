#include "Character.h"

void Character::render(){
	SDL_RenderCopy( texture->getRenderer(), texture->getTexture(), &spriteSheetLoc, &worldLoc ); //render the sprite to the canvas
}

void Character::setTexturePointer(Texture* _texture){
	texture=_texture;//set the texture pointer
	
}

void Character::move(){//the move method
}

Character::~Character()
{
	//dtor
}
