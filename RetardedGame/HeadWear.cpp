#include "HeadWear.h"


HeadWear::HeadWear()
{
}

void HeadWear::render(SDL_Rect spriteSheetLoc, SDL_Rect relativeLoc)
{
	relativeLoc.y -= 11;
	Item::render(spriteSheetLoc, relativeLoc);
}

HeadWear::~HeadWear()
{
}
