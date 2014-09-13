#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

SDL_Event event;

int main(int argc,char * argv[])
{
	bool success=true;
	SDL_Window* window;
	SDL_Renderer* renderer = NULL;
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		cout<<"SDL could not initialize! SDL Error: "<< SDL_GetError()<<endl;
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			cout<<"Warning: Linear texture filtering not enabled!"<<endl;
		}

		//Create window
		window = SDL_CreateWindow( "the test app", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 50, 50, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			cout<<"Window could not be created! SDL Error: "<< SDL_GetError() <<endl;
			success = false;
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
			if( renderer == NULL )
			{
				cout<<"Renderer could not be created! SDL Error: "<< SDL_GetError() <<endl;
				success = false;
			}
			
		}
	}
	
	if(success){
		bool quit=false;
		while(quit==false){
			while(SDL_PollEvent( &event )){
				switch (event.type){
					case SDL_KEYDOWN:
						cout<<"some button was pressed"<<endl;
						break;//end case SDL_KEYDOWN:
					case SDL_QUIT:
						quit = true;
						break;
				}//end switch (event.type)
			}//end while(SDL_PollEvent( &event ))
		}//end while(quit==false)
	}
	
	
    return 0;
}
