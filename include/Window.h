#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Texture.h"
using namespace std;

class Window
{
	bool success;

	SDL_Rect cameraLocation;//the x and y params is where you should start rendering from the canvas
	SDL_Rect sceneSize;//the h and w params are the size of the screen
	SDL_Window* window;// the window of this window
	SDL_Renderer* renderer = NULL;//the rnderer
	Texture canvas;//the canvas
	int winWidth = 256;//the initial width of the window
	int winHeight = 240;//the initial height of the window
	public:
		bool resized;
		Window();
		void clearFrame();
		void renderFrame();
		void windowEventHandler(SDL_Event event);
		SDL_Window* getWindow();
		SDL_Renderer* getRenderer();
		bool windowExists();
		~Window();
	protected:
	private:

};

#endif // WINDOW_H
