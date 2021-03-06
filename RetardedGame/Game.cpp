#include "Game.h"



Game::Game(){
	box = new Texture(); //create a new texture. This will be the universal sprite sheet texture
	

	mapTexture = new Texture(); //create a new texture. This will be the universal sprite sheet texture
	player = new Texture();

	setTextures();

	win.setCanvasSize();

	mapData = &map.getMap();
	
	map = Map(win.getRenderer());
	map.setTexturePointer(mapTextures);

	
	enemies.push_back(EnemyFactory::create("enemy", box));//the factory method example
	enemies.push_back(EnemyFactory::create("enemy", box));

	
	p.setTexturePointer(player);//create a pointer to the spritesheet
	p.setMapPointer(mapData);

	Texture* hatTex = new Texture();
	hatTex->setRenderer(win.getRenderer());
	hatTex->makeTexture("Images/afro.png");

	hat=new HeadWear();
	hat->setTexturePointer(hatTex);

	p.setHat(hat);

	//Enemy* e = EnemyFactory::create("enemy", box); //the factory method example
}

void Game::run(){
	if (win.windowExists()){
		FpsCapper fps;//create a FPS capper
		bool quit = false; //sets the main loop exit flag

		while (!quit){
			fps.start(); //start point of the fps capper/counter
			while (SDL_PollEvent(&event)){

				win.windowEventHandler(event);//checks if any window happened and handles them
				p.eventHandler(event); //checks if any keyboard event happened

				if (win.resized){ //if window was resized, reset the textures
					setTextures();
					win.resized = false;
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


			p.gravity();//gravity of the player

			//Collision detection


			vector<vector<int>> mapArray = map.getMap();//the part that i just deleted comes from here

			SDL_Rect playerSize = p.getPlayerLocation();
		
			if ((mapArray[(playerSize.y + playerSize.h) / 50][(playerSize.x + playerSize.w) / 50] != 0) // lower right border of the player
				|| (mapArray[(playerSize.y + playerSize.h) / 50][(playerSize.x + 10) / 50] != 0)) // lower left border of the player
			{
				
				//cout << " OUCH!!! FLOOR" << endl;
				p.move("bottom");
				//Lock movement here
			}

			else if ((mapArray[p.getPlayerLocation().y / 50][p.getPlayerLocation().x / 50] != 0) || (mapArray[(p.getPlayerLocation().y) / 50][(p.getPlayerLocation().x + 50) / 50] != 0)) //&&(p.moving==false))
			{
				p.move("top");
				//cout << " OUCH!!! ROOF";
			}

			

			if (p.isMoving()){//move player if keys are pressed
				p.move(p.movement);
			}


			p.setRelativeCoord(map.render(p.getPlayerLocation()));

			//e->gravity();//gravity of the enemy

			
			render();

			p.collisionHandler(collision);

			string fpsText = "The average FPS is: " + to_string(fps.getAvgFps());
			SDL_SetWindowTitle(win.getWindow(), fpsText.c_str());

			fps.frameRendered();//set the timer of the frame renderer correctly
			fps.cap(); //keep the fps capped 


		}//end while(quit==false)
	}//end if(win.windowExists())
}

void Game::render(){
	for (int i = 0; enemies.size() > i; i++){
		enemies.at(i)->render();
		//enemies.at(i)->gravity();
		collision = enemies.at(i)->collision(p.getPlayerLocation());
	}

	p.collisionHandler(collision);

	p.render();//render player to canvas
	win.renderFrame(p.getRelativePlayerLocation());//render canvas to screen
}

void Game::setTextures(){
	player->setRenderer(win.getRenderer());
	player->makeTexture(playerPicture);

	box->setRenderer(win.getRenderer());
	box->makeTexture(characterPictures);

	//p.setTexturePointer(mapTextures);
}

Game::~Game(){
	delete box;
	delete hat;
	//delete mapData;
	for (int i = 0; enemies.size() > i; i++){
		delete enemies.at(i);
	}
}
