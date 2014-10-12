#include "Window.h"

Window::Window(){
	//initializes the window related flags
	resized=false; 
	success=true;
	
	sceneSize={0,0,winWidth,winHeight};
	cameraLocation={0,0,winWidth,winHeight};
	
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ){
		cout<<"SDL could not initialize! SDL Error: "<< SDL_GetError()<<endl;
		success = false;
	}
	else{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
			cout<<"Warning: Linear texture filtering not enabled!"<<endl;
		}
		//Create window
		window = SDL_CreateWindow( "the test app", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, winWidth, winHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
		if( window == NULL ){
			cout<<"Window could not be created! SDL Error: "<< SDL_GetError() <<endl;
			success = false;
		}
		else{
			//Create renderer for window
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
			if( renderer == NULL ){
				cout<<"Renderer could not be created! SDL Error: "<< SDL_GetError() <<endl;
				success = false;
			}
			else{
				

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) ){
					cout<<"SDL_image could not initialize! SDL_image Error: "<< IMG_GetError() <<endl;
					success = false;
				}
			}
			
		}
	}
	
	
}

void Window::setCanvasSize(Texture* texture){
	//if window was created, initialise the canvas
	if (success){
		canvasSize=texture->getSize();
		canvas.setRenderer(renderer);
		canvas.makeBlankTexture(canvasSize.w, canvasSize.h);
	}
}

void Window::clearFrame(){//clear a texture
	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( renderer );
}

void Window::renderFrame(SDL_Rect playerLoc){
	
	SDL_SetRenderTarget(renderer,NULL); //set the window back as the rendering target
	clearFrame();//clear the window
	
	int playerCenterX = playerLoc.x + (playerLoc.w / 2);
	int playerCenterY = playerLoc.y + (playerLoc.h / 2);

	int cameraCenterX = winWidth / 2;
	int cameraCenterY = winHeight / 2;

	if ((playerCenterX - cameraCenterX) < 0){
		cameraLocation.x = 0;
	}
	else if (playerCenterX + (winWidth / 2)>canvasSize.w){
		cameraLocation.x = canvasSize.w - winWidth;
	}
	else{
		cameraLocation.x = playerCenterX - cameraCenterX;
	}

	if ((playerCenterY - cameraCenterY) < 0){
		cameraLocation.y = 0;
	}
	else if (playerCenterY + (winHeight / 2)>(canvasSize.h)){
		cameraLocation.y = canvasSize.h - winHeight;
	}
	else{
		cameraLocation.y = playerCenterY - cameraCenterY;
	}
	
	

	cout << (canvasSize.h - winHeight) << endl;

	SDL_RenderCopy( renderer, canvas.getTexture(),&cameraLocation , &sceneSize );//render the the wanted part of the scene onto the screen
	
	
	SDL_RenderPresent(renderer); //show the screen
	SDL_SetRenderTarget(renderer,canvas.getTexture());//set the canvas as the rendering target
	
	
}

void Window::windowEventHandler(SDL_Event event){
	switch( event.window.event ){
		case SDL_WINDOWEVENT_SIZE_CHANGED://if the window size has changed...
			winWidth=event.window.data1;//...change the window attributes
			winHeight=event.window.data2;
			
			cameraLocation.w=winWidth;//reset the camera related structs
			cameraLocation.h=winHeight;
			
			sceneSize.w=winWidth;
			sceneSize.h=winHeight;
			
			SDL_DestroyRenderer( renderer );//destroy the renderer
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );//recreate the renderer
			
			canvas.setRenderer(renderer);//reinitialize the canvas
			canvas.makeBlankTexture(canvasSize.w, canvasSize.h);
			
			resized=true;//set the resized flag
			
			break;
	}
	
}

SDL_Window* Window::getWindow(){
	return window;//return the pointer to the window object
}

SDL_Renderer* Window::getRenderer(){
	return renderer;//return the pointer to the renderer object
}

bool Window::windowExists(){
	return success;//return the window was created flag
}

Window::~Window()
{
	//Destroy window	
	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( renderer );
	
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
