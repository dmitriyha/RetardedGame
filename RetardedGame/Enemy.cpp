#include "Enemy.h"


Enemy::Enemy(){
	spriteSheetLoc = { 0, 50, 50, 50 };//where the player sprite is on the sprite sheet
	worldLoc = { 150, 50, 50, 50 };//where the player will go on the canvas
}

void Enemy::move(){

}

bool Enemy::collision(SDL_Rect playerLoc){
	SDL_bool collision = SDL_HasIntersection(&playerLoc, &worldLoc);

	if (collision == SDL_TRUE){
		return true;
	}
	else{
		return false;
	}
}

Enemy::~Enemy()
{
}
