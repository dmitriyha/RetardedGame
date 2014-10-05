#include <iostream>
#include <string>
#include <SDL.h>
#include "Window.h"
#include "Texture.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "FpsCapper.h"
#include "EnemyFactory.h"
using namespace std;



int main(int argc,char ** argv)
{
	SDL_Event event;//create an even to poll
	Window win;//create a window
	
	Texture* box =new Texture(); //create a new texture. This will be the universal sprite sheet texture
	box->setRenderer(win.getRenderer()); // set the renderer for the texture
	box->makeTexture("Images\\lol.png"); //set the spritesheet
	
	Player p;//create a player object
	p.setTexturePointer(box);//create a pointer to the spritesheet
	
	Enemy* e = EnemyFactory::create("enemy", box); //the factory method example

	if(win.windowExists()){
		FpsCapper fps;//create a FPS capper
		bool quit=false; //sets the main loop exit flag
		
		while(!quit){
			fps.start(); //start point of the fps capper/counter
			while(SDL_PollEvent( &event )){
				
				win.windowEventHandler(event);//checks if any window happened and handles them
				p.eventHandler(event); //checks if any keyboard event happened
				
				if(win.resized){ //if window was resized, reset the textures
					box->setRenderer(win.getRenderer());
					box->makeTexture("Images\\lol.png");
					win.resized=false;
				}
				
				switch (event.type){//if window was closed, set the quit flag
					case SDL_QUIT:
						quit = true;
						break;
					default:
						break;
				}//end switch (event.type)
			}//end while(SDL_PollEvent( &event ))
			
			win.clearFrame();//clears the frame in preperation of the next frame
			
			if(p.isMoving()){//move player if keys are pressed
				p.move();
			}
			
			p.gravity();//gravity of the player
			e->gravity();//gravity of the enemy

			e->render();//render the enemy object
			p.render();//render player to canvas
			win.renderFrame();//render canvas to screen
			
			string fpsText="The average FPS is: "+to_string(fps.getAvgFps());
			SDL_SetWindowTitle(win.getWindow(),fpsText.c_str());
			
			fps.frameRendered();//set the timer of the frame renderer correctly
			fps.cap(); //keep the fps capped 
			
			
		}//end while(quit==false)
	}//end if(win.windowExists())
	
	delete box;
	
    return 0;
}