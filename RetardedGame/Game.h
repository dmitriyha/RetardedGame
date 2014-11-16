#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include "Window.h"
#include "Texture.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "FpsCapper.h"
#include "EnemyFactory.h"
#include "Map.h"
#include <vector>
using namespace std;

class Game{
	const string playerPicture = "Images\\tail_sprite2x.png";
	const string characterPictures = "Images\\lol.png";
	const string mapPicture = "Images\\BasicMap.png";

	SDL_Event event;//create an even to poll
	Window win;//create a window
	Map map;
	Player p;//create a player object
	vector<Enemy*> enemies;
	Texture* box;
	Texture* player;
	Texture* mapTexture;

	bool collision;
public:
	Game();
	void run();
	~Game();
	
private:
	void setTextures();
	void render();
};

