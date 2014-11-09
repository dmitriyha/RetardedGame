#include "Player.h"
#include "Map.h"


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


	Map map;
	MapStructure mapArray = map.getMap();//the part that i just deleted comes from here


	int positionTiles[2];

	if (movement == "right")
	{
		
		//cout << worldLoc.x;
		//cout << "\n";

		//cout << "\n";
		//cout << worldLoc.y;
		positionTiles[0] = (worldLoc.x + 50) / 50; //Adding 50 pixels, because player is 50px wide. HARDCODED
		positionTiles[1] = worldLoc.y / 50;
		
		cout << positionTiles[0] << "\n";

		cout << positionTiles[1] << "\n";
		

		/*

		if ((mapArray.map[positionTiles[1]][positionTiles[0]] != 0) && (mapArray.map[(worldLoc.y + 50)/ 50][positionTiles[0]] != 0))
		{
			worldLoc.x = worldLoc.x;
			//worldLoc.y = (worldLoc.y / 50) * 50;

		}
		else if (mapArray.map[positionTiles[1]][positionTiles[0]] != 0)
		{
			worldLoc.x = worldLoc.x;
		}

		*/

		if(mapArray.map[positionTiles[1]][positionTiles[0]] == 0)
		{
			worldLoc.x = worldLoc.x + 2;
		}

	}

	else if (movement == "left")
	{
		
		//cout << worldLoc.x;
		//cout << "\n";
		//cout << worldLoc.y;

		positionTiles[0] = worldLoc.x / 50;
		positionTiles[1] = worldLoc.y / 50;

		cout << positionTiles[0] << "\n";

		cout << positionTiles[1] << "\n";

		if (mapArray.map[positionTiles[1]][positionTiles[0]] == 0)
		{
			worldLoc.x = worldLoc.x - 2;
		}

		//cout << "\n";
	}

	else if (movement == "jump")
	{
		//if (collision){
			collision = false;


			//gravityVelocity = -5;
			positionTiles[0] = worldLoc.x / 50;
			positionTiles[1] = worldLoc.y / 50;

			//cout << positionTiles[0] << "\n";

			//cout << positionTiles[1] << "\n";

			//if (map[positionTiles[1]][positionTiles[0]] == 0)
			//{
				gravityVelocity = -5;
			//}

			//else
			//{
			//	gravityVelocity = 0;
			//}

			//worldLoc.y = (480 - spriteSheetLoc.h) - 1;
		//}
		
	}

	else if (movement == "bottom")
	{
		int right = (worldLoc.x + 50) / 50;
		int left = worldLoc.x / 50;
		positionTiles[1] = worldLoc.y / 50;

		if (((mapArray.map[positionTiles[1]][right] != 0) || (mapArray.map[positionTiles[1]][left] != 0)))

		{
			if ((mapArray.map[positionTiles[1] + 1][right - 1] != 0) || (mapArray.map[positionTiles[1] + 1][left - 1] != 0))
			{
				gravityVelocity = 0;
			}
			
			else
			{
				gravityVelocity = 4;
			}


		}
		else
		{
			worldLoc.y = (worldLoc.y / 50) * 50;
			worldLoc.x = worldLoc.x;
			gravityVelocity = 0;
		}
				
	}
	else if (movement == "top") 
	{
		worldLoc.x = worldLoc.x;
		worldLoc.y = ((worldLoc.y+50) / 50) * 50;

		//if (mapArray.map[positionTiles[1]][positionTiles[0]] == 0)
		//{

		//}
		gravityVelocity = 0;
	}

	//worldLoc.y++;
}

void Player::collisionHandler(bool collision){
	if (previousTickCount == 0){//sets the timer to current time if it was cleared
		currentTickCount = SDL_GetTicks();
		previousTickCount = SDL_GetTicks();
	}
	else{ //sets the timer to current time and makes sure the time from last check is able to be calculated
		previousTickCount = currentTickCount;
		currentTickCount = SDL_GetTicks();
	}

	if (collision && invulnTime == 0){ //if a collision occured, take a hit
		hit = true;
		lives--;
	}
	else if (invulnTime > 2000){//2 second invunerability time, after which let the player take another hit
		hit = false;
		invulnTime = 0;
	}

	if (hit){ //if the playeer was hit, flash the player image
		invulnTime += (currentTickCount - previousTickCount);
		flashTime += (currentTickCount - previousTickCount);
		if (flashTime > 200){//a 0.2 second flash time
			if (spriteSheetLoc.h > 0){//this sets the player to invisible
				spriteSheetLoc.h = 0;
				spriteSheetLoc.w = 0;
			}
			else{//this sets the player to visible
				spriteSheetLoc.h = spriteHeight;
				spriteSheetLoc.w = spriteWidth;
			}
			flashTime = 0;
		}
	}
	else{//reset times and texture
		flashTime = 0;
		invulnTime = 0;
		spriteSheetLoc = { 0, 0, spriteWidth, spriteHeight };
	}
}

Player::~Player()
{
	//dtor
}
