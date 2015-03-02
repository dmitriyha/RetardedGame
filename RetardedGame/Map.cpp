#include "Map.h"

Map::Map(){}

Map::Map(SDL_Renderer* render)
{
	MapParser parser;
	parser.readFile("Maps\\1-Museum.txt");
	header = parser.getMapHeader();
	tileSet = parser.getTilesetData();
	layers = parser.getLayers();
	//cout << layers.at(0).layerData.at(0).at(0) << endl;

	

	for (int i = 0; i < layers.size(); i++){
		if (layers.at(i).type.find("CHARACTER") != string::npos){ //checks to see if the specified substring was found
			map = layers.at(i).layerData;
		}
	}

	int texturesX = (header.width * header.tileWidth) / 1000;
	int texturesY = (header.height * header.tileHeight) / 1000;

	int tilesPerTexX = header.width / texturesX;
	int tilesPerTexY = header.height / texturesY;


	

	texture.reserve(texturesY);
	for (int i = 0; i < texture.capacity(); i++){
		vector<Texture*> v;
		v.reserve(texturesX);
		for (int j = 0; j < texture.capacity(); j++){
			
			Texture *tex = new Texture();
			tex->setRenderer(render);
			tex->makeBlankSurface(1000, 1000);
			v.push_back(tex);
		}
		texture.push_back(v);
	}


	Texture tiletex;
	tiletex.setRenderer(render);
	tiletex.makeSurface(tileSet.at(0).tileSet);

	int x = 0, y = 0;

	for (int k = 0; k < header.height; k++)
	{
		bool entry = true;
		for (int l = 0; l < header.width; l++)
		{
			SDL_Rect worldLoc = { ((l % tilesPerTexX) * header.tileWidth), ((k % tilesPerTexY) * header.tileHeight), header.tileWidth, header.tileHeight };
			SDL_Rect tileLoc = { 0, 0, header.tileWidth, header.tileHeight };

			
			if (map[k][l] == 1 || map[k][l] == 0){
				tileLoc.x = 0;
				tileLoc.y = 0;

				

			}
			else
			{

				

				int tile = (map[k][l] - 1) % 8;
				int row = (map[k][l] - 1)/ 8;

				

				

				//cout << tile << endl;

				tileLoc.x = tile * header.tileWidth;
				tileLoc.y = row * header.tileHeight;

				if (map[k][l] == 40)
				{
					cout << tile << " " << row << " " << endl;
				}

				if (k == 1 && l == 3){

					cout << worldLoc.x << " " << worldLoc.y << " " << map[k][l] << endl;

				}

			}
			SDL_BlitSurface(tiletex.getSurface(), &tileLoc, texture.at(y).at(x)->getSurface(), &worldLoc);

			if ((l % tilesPerTexX) == tilesPerTexX - 1){
				x++;
				if (x == texture.at(y).capacity()){
					x = 0;
				}

			}

			if (((k % tilesPerTexY) == tilesPerTexY - 1) && entry ){
				y++;
				if (y == texture.capacity()){
					y = 0;
				}
				entry = false;
			}

		}
	}
		

	for (int i = 0; i < texture.capacity(); i++){
		for (int j = 0; j < texture.at(i).capacity(); j++){
			texture.at(i).at(j)->convertSurfaceToTexture();
		}
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

	int firstTextureX = 0;
	if (xLoc < 1){
		firstTextureX = xLoc;
	}
	else if (xLoc > 0 && xLoc < (texture.at(firstTextureY).size() - 1)){
		relativeCoord.x = 1;
		firstTextureX = xLoc - 1;
	}
	else if (xLoc >= texture.at(firstTextureY).size() - 1){
		relativeCoord.x = 2;
		firstTextureX = texture.at(firstTextureY).size() - 3;
	}

	for (int i = 0; i < 3; i++){
		
		for (int j = 0; j < 3; j++){
			SDL_Rect size = { ((j)* 1000), ((i)* 1000), 1000, 1000 };
			//cout << i << " " << j << " " << texture.at(firstTextureY + i).size() << endl;
			
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
