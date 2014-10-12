#include "Enemy.h"


Enemy::Enemy(){
	spriteSheetLoc = { 0, 50, 50, 50 };//where the player sprite is on the sprite sheet
	worldLoc = { 100, 50, 50, 50 };//where the player will go on the canvas
}

void Enemy::move(){

}

Enemy::~Enemy()
{
}
