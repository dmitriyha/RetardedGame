#pragma once

#include <vector>
#include "Texture.h"
#include "MapStructure.h"
#include "CoordinateStruct.h"

class Map
{

	vector <Texture*> texture;//the pointer to the sprite sheet
	MapStructure map;

public:
	Map();
	CoordinateStruct render(SDL_Rect playerLoc);
	void setTexturePointer(vector<Texture*> _texture );
	MapStructure getMap();
	

	~Map();
};

