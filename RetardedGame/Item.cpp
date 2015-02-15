#include "Item.h"

void Item::setTexturePointer(Texture* _texture){
	texture = _texture;
}

bool Item::isEquipped(){
	return equipped;
}

void Item::render(SDL_Rect spriteSheetLoc, SDL_Rect relativeLoc) {
	SDL_RenderCopy(texture->getRenderer(), texture->getTexture(), &spriteSheetLoc, &relativeLoc);
}

Item::~Item()
{
}
