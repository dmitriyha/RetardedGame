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
	const string mapString1 = "Images\\map1.png";
	const string mapString2 = "Images\\map2.png";
	const string mapString3 = "Images\\map3.png";
	const string mapString4 = "Images\\map4.png";
	vector<Texture*> mapTextures;

	const vector<vector<int>>* mapData;

	SDL_Event event;//create an even to poll
	Window win;//create a window
	Map map;
	Player p;//create a player object
	vector<Enemy*> enemies;
	Texture* box;
	Texture* map1;
	Texture* map2;
	Texture* map3;
	Texture* map4;
	Texture* player;
	Texture* mapTexture;

	HeadWear* hat;

	bool collision;
public:
	Game();
	void run();
	~Game();
	
private:
	void setTextures();
	void render();
};

