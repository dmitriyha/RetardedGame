#pragma once
#include "Texture.h"

class Map
{

	Texture* texture;//the pointer to the sprite sheet
public:
	Map();
	void render();
	void setTexturePointer(Texture* _texture);
	

	~Map();
};

