#pragma once
#include "Texture.h"
#include "MapStructure.h"

class Map
{

	Texture* texture;//the pointer to the sprite sheet

	MapStructure map;

	
public:
	Map();
	void render();
	void setTexturePointer(Texture* _texture);
	MapStructure getMap();

	~Map();
};

