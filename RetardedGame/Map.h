#pragma once

#include <vector>
#include "MapParser.h"
#include "Texture.h"
#include "MapStructure.h"
#include "CoordinateStruct.h"

class Map
{

	vector <vector<Texture*>> texture;//the pointer to the sprite sheet
	vector<vector<int>> map;
	MapHeader header;
	vector<TileSet> tileSet;
	vector<Layer> layers;
	

public:
	Map();
	Map(SDL_Renderer* render);
	CoordinateStruct render(SDL_Rect playerLoc);
	void setTexturePointer(vector<Texture*> _texture );
	vector<vector<int>> &getMap();
	

	~Map();
};

