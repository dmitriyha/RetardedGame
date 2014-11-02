#include "Map.h"


Map::Map()
{
	
}


void Map::render(){
	SDL_RenderCopy(texture->getRenderer(), texture->getTexture(), NULL, NULL); //render the sprite to the canvas
}

void Map::setTexturePointer(Texture* _texture){
	texture = _texture;//set the texture pointer

}

Map::~Map()
{
}
