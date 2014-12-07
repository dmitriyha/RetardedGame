#include "Map.h"

Map::Map(){}

Map::Map(SDL_Renderer* render)
{
	MapParser parser;
	parser.readFile("Maps\\BasicMap.txt");
	header = parser.getMapHeader();
	tileSet = parser.getTilesetData();
	layers = parser.getLayers();
	//cout << layers.at(0).layerData.at(0).at(0) << endl;

	for (int i = 0; i < layers.size(); i++){
		if (layers.at(i).type.find("CHARACTER") != string::npos){ //checks to see if the specified substring was found
			map = layers.at(i).layerData;
		}
	}

	cout << map[1][0] << endl;

	int texturesX = (header.width * header.tileWidth) / 1000;
	int texturesY = (header.height * header.tileHeight) / 1000;

	texture.reserve(texturesY);

	Texture tiletex;
	tiletex.setRenderer(render);
	tiletex.makeSurface(tileSet.at(0).tileSet);

	int x = 0, y = 0;

	for (int i = 0; i < texture.capacity(); i++){
		vector<Texture*> v;
		v.reserve(texturesX);
		for (int j = 0; j < v.capacity(); j++){
			Texture *tex = new Texture();
			tex->setRenderer(render);
			tex->makeBlankSurface(1000, 1000);

			/*SDL_SetRenderTarget(render, tex->getTexture());

			SDL_SetRenderDrawColor(render, 128, 128, 128, 0);
			SDL_RenderClear(render);*/

			for (int k = 0; k < (header.height); k++){
				for (int l = 0; l < (header.width/texturesX); l++){
					SDL_Rect worldLoc = { (l * header.tileWidth), (k * header.tileHeight), header.tileWidth, header.tileHeight };
					SDL_Rect tileLoc = { 0, 0, header.tileWidth, header.tileHeight };
					
					if (map[k][x + l] == 1 || map[k][x + l] == 0){
						tileLoc.x = 0;
						tileLoc.y = 0;
					}
					else{
						int tile = map[k][l + x] - 1;
						int row = map[k][l + x] / 8;

						if (tile > row){
							tile = tile - (row * 8);
						}

						cout << row << endl;

						tileLoc.x = tile * header.tileWidth;
						tileLoc.y = row * header.tileHeight;
					}

					SDL_BlitSurface(tiletex.getSurface(), &tileLoc,tex->getSurface(), &worldLoc);

						
				}
			}
			x += header.width / texturesX;
			y++;

			tex->convertSurfaceToTexture();

			v.push_back(tex);
		}
		texture.push_back(v);
	}

	SDL_SetRenderTarget(render, NULL);

	/*for (int i = 0; i < 20; i++){
		vector<int> v;
		for (int j = 0; j < 200; j++){
			
			v.push_back(_map[i][j]);
		}
		map.push_back(v);
	}*/
}


CoordinateStruct Map::render(SDL_Rect playerLoc){
	float xLoc = playerLoc.x / 1000;
	float yLoc = playerLoc.y / 1000;

	CoordinateStruct relativeCoord{ 0, 0 };

	int firstTextureX=0;
	if (xLoc < 1){
		firstTextureX = xLoc;
	}
	else if (xLoc > 0 && xLoc < (texture.at(0).size() - 1)){
		relativeCoord.x = 1;
		firstTextureX = xLoc-1;
	}
	else if (xLoc >= texture.at(0).size()-1){
		relativeCoord.x = 2;
		firstTextureX = texture.at(0).size() - 3;
	}

	int firstTextureY = 0;
	if (yLoc < 1){
		firstTextureY = yLoc;
	}
	else if (yLoc > 0 && yLoc < (texture.size() - 1)){
		relativeCoord.y = 1;
		firstTextureY = yLoc - 1;
	}
	else if (yLoc >= texture.size() - 1){
		relativeCoord.y = 2;
		firstTextureY = texture.size() - 3;
	}


	for (int i = 0; i < 3 && ((i + texture.size()) <= texture.size()); i++){
		for (int j = 0; j < 3; j++){
			SDL_Rect size = { ((j)* 1000), ((i)* 1000), 1000, 1000 };

			SDL_RenderCopy(texture.at(firstTextureY + i).at(firstTextureX + j)->getRenderer(), texture.at(firstTextureY + i).at(firstTextureX + j)->getTexture(), NULL, &size); //render the sprite to the canvas
		}
	}

	return relativeCoord;
}

void Map::setTexturePointer(vector<Texture*> _texture){
	//texture = _texture;//set the texture pointer

}

vector<vector<int>> &Map::getMap(){
	
	return map;
}

Map::~Map()
{
}
