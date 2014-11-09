#pragma once
#include "Texture.h"
#include "MapStructure.h"
#include <vector>

class Map
{

	vector <Texture*> texture;//the pointer to the sprite sheet
	MapStructure map;

public:
	Map();
	void render(SDL_Rect playerLoc);
	void setTexturePointer(vector<Texture*> _texture );
	MapStructure getMap();
	

	~Map();
};

