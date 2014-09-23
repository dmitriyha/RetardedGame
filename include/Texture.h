#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

class Texture
{
	SDL_Renderer* renderer;//the renderer pointer
	SDL_Texture* texture;//the texture pointer
	int width,height;//the width and height of the texture
	public:
		Texture ();
		void makeTexture(string path);
		void makeBlankTexture(int _width, int _height);
		SDL_Texture* getTexture();
		SDL_Renderer* getRenderer();
		void setRenderer(SDL_Renderer* _renderer);
		void free();
		~Texture();
	protected:
	private:
		
};

#endif // TEXTURE_H
