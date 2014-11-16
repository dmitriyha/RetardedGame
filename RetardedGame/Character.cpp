#include "Character.h"

Character::Character(){
	relativeLoc={0,0,0,0};
}

void Character::render(){
	relativeLoc = worldLoc;

	if (worldLoc.x >= 2000 && location.x < 2){
		int x = worldLoc.x;
		x = x - (((x/1000)*1000)-1000);
		relativeLoc.x = x;
	}
	else if(location.x==2){
		int x = worldLoc.x;
		relativeLoc.x = x-((x / 1000) * 1000)+2000;
		cout << relativeLoc.x << endl;
	}

	SDL_RenderCopy(texture->getRenderer(), texture->getTexture(), &spriteSheetLoc, &relativeLoc);//render the sprite to the canvas
}

void Character::setTexturePointer(Texture* _texture){
	texture = _texture;//set the texture pointer
}

void Character::gravity(){
	
	gravityVelocity = gravityVelocity + gravityConstant;
	
	if (gravityVelocity > maxGravityVelocity){
		gravityVelocity = maxGravityVelocity;
	}

	/* the collision detection that stopped it at the old screen borders

	if (worldLoc.y >= 480 - spriteSheetLoc.h){

		worldLoc.y = (480 - spriteSheetLoc.h) ;
		
		collision = true;
	}
	
	if (collision){
		gravityVelocity = 0;
	}*/

	worldLoc.y = worldLoc.y + (gravityVelocity );
}

void Character::move(){//the move method
}

void Character::collisionHandler(bool _collision){

}

Character::~Character()
{
	//dtor
}
