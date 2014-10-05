#include "Item.h"

void Item::setTexturePointer(Texture* _texture){
	texture = _texture;
}

bool Item::isEquipped(){
	return equipped;
}

void Item::renderItem() {

}

Item::~Item()
{
}
