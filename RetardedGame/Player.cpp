#include "Player.h"
#include "Map.h"


Player::Player(){
	spriteSheetLoc={0,0,50,50};//where the player sprite is on the sprite sheet
	worldLoc={50,50,50,50};//where the player will go on the canvas
	//HARDCODED MAP
	
	
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

		if (mapArray.map[positionTiles[1]][positionTiles[0]] == 0)
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

		//cout << positionTiles[0] << "\n";

		//cout << positionTiles[1] << "\n";

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

	//worldLoc.y++;
}

Player::~Player()
{
	//dtor
}
