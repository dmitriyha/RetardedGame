#pragma once
#include "Texture.h"

class Map
{

	Texture* texture;//the pointer to the sprite sheet
public:
	Map();
	int map[20][200];
	void render();
	void setTexturePointer(Texture* _texture);
	

	~Map();
};

