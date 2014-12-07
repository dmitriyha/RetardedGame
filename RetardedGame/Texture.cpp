#include "Texture.h"

Texture::Texture(){
	//sets up the texture for use
	texture = NULL;
	width = height = 0;
	
	free(); 
}

void Texture::makeTexture(string path){//makes a texture from the picture
	free();
	loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL ){
		cout<<"Unable to load image "<< path.c_str()<<"  SDL_image Error: " << IMG_GetError() <<endl;
	}
	else{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 128, 128, 128) );

		//Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
		if( texture == NULL ){
			cout<<"Unable to create texture from "<<path.c_str()<<" SDL Error: "<< SDL_GetError() <<endl;
		}
		else{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
}



void Texture::makeBlankTexture(int _width, int _height){//makes a canvas
	free();
	//Create uninitialized texture 
	texture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _width, _height ); 
	if( texture == NULL ) {
		cout<<"Unable to create blank texture! SDL Error: " << SDL_GetError() << endl; 
	} 
	else { 
		width = _width; 
		height = _height;
	} 
}

void Texture::makeSurface(string path){
	free();
	loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL){
		cout << "Unable to load image " << path.c_str() << "  SDL_image Error: " << IMG_GetError() << endl;
	}
}

void Texture::makeBlankSurface(int _width, int _height){
	loadedSurface = SDL_CreateRGBSurface(0, _width, _height, 32, 0x0, 0x0, 0x0, 0xff);
	if (loadedSurface == NULL){
		cout << "Unable to create blank surface SDL Error: " << SDL_GetError() << endl;
	}
}

SDL_Rect Texture::getSize(){
	SDL_Rect size;
	size.w = width;
	size.h = height;
	return size;
}

SDL_Texture* Texture::getTexture(){//gets the texture object
	if( texture == NULL ) {
		return NULL;
	}
	else{
		return texture;
	}
}

void Texture::convertSurfaceToTexture(){
	if (loadedSurface == NULL){
		cout << "Unable to find surface SDL Error: " << SDL_GetError() << endl;
	}
	else{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 128, 128, 128));

		//Create texture from surface pixels
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
		if (texture == NULL){
			cout << "Unable to create texture from surface SDL Error: " << SDL_GetError() << endl;
		}
		else{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
}

SDL_Surface* Texture::getSurface(){//gets the texture object
	if (loadedSurface== NULL) {
		return NULL;
	}
	else{
		return loadedSurface;
	}
}

void Texture::setRenderer(SDL_Renderer* _renderer){//sets the renderer object
	renderer=_renderer;
}

SDL_Renderer* Texture::getRenderer(){//gets the renderer object
	return renderer;
}

void Texture::free(){//frees the texture
	if( texture != NULL ){
		SDL_DestroyTexture( texture );
		texture = NULL;
		width = 0;
		height = 0;
	}
}

Texture::~Texture()
{
	free();
}
