#pragma once
#include "Item.h"
class HeadWear :
	public Item
{
public:
	HeadWear();
	virtual void render(SDL_Rect spriteSheetLoc, SDL_Rect relativeLoc);
	virtual ~HeadWear();
};

