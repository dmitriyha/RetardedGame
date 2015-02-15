#include "HeadWear.h"


HeadWear::HeadWear()
{
}

void HeadWear::render(SDL_Rect spriteSheetLoc, SDL_Rect relativeLoc)
{
	Item::render(spriteSheetLoc, relativeLoc);
}

HeadWear::~HeadWear()
{
}
