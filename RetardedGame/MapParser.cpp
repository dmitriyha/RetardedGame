#include "MapParser.h"


MapParser::MapParser()
{
}

void MapParser::readFile(string name){
	string line;
	ifstream file(name);
	if (file.is_open()){
		while (getline(file, line)){
			fileString.append(line + "\n");
		}
		file.close();
	}
	else { cout << "error reading file " << name << endl; }

	
	MapHeader map = getMapHeader();
	vector<TileSet> t = getTilesetData();

	//string s= findTag("[layer]", 3);

	vector<Layer>l=getLayers();
	cout << l.at(2).layerData.at(18).at(8) << endl;
}

MapHeader MapParser::getMapHeader(){
	string width = "width=";
	string height = "height=";
	string tilewidth = "tilewidth=";
	string tileheight = "tileheight=";


	string headerData = findTag("[header]");

	vector<string> headerList = getProperties(headerData);

	MapHeader map;
	map.width = stoi(headerList.at(0).substr(width.length(), headerList.at(0).length()));
	map.height = stoi(headerList.at(1).substr(height.length(), headerList.at(1).length()));
	map.tileWidth = stoi(headerList.at(2).substr(tilewidth.length(), headerList.at(2).length()));
	map.tileHeight = stoi(headerList.at(3).substr(tileheight.length(), headerList.at(3).length()));
	return map;
}

vector<TileSet> MapParser::getTilesetData(){
	vector<TileSet> returnable;

	string tileset = "tileset=";
	string tilesetData = findTag("[tilesets]");
	vector<string> tilsetList = getProperties(tilesetData);

	for (int i = 0; i < tilsetList.size();i++){
		TileSet tilesetData;
		int prev = 0, next = 0, length = 0;
		string dataString = tilsetList.at(i).substr(tileset.length(), tilsetList.at(i).length());
		
		next = dataString.find(",", prev + 1)+1;
		length = next - prev - 1;

		tilesetData.tileSet = dataString.substr(prev, length);

		prev = next ;
		next = dataString.find(",", prev ) + 1;
		length = next - prev - 1;

		tilesetData.tileWidth = stoi(dataString.substr(prev, length));

		prev = next  ;
		next = dataString.find(",", prev) + 1;
		length = next - prev - 1;

		tilesetData.tileHeight = stoi(dataString.substr(prev, length));

		prev = next ;
		next = dataString.find(",", prev) + 1;
		length = next - prev - 1;

		tilesetData.mysteryVariableA = stoi(dataString.substr(prev, length));

		prev = next;
		next = dataString.find(",", prev ) + 1;
		length = next - prev - 1;

		tilesetData.mysteryVariableB = stoi(dataString.substr(prev, length));
		returnable.push_back(tilesetData);
	}

	
	return returnable;
}

vector<Layer> MapParser::getLayers(){
	vector<Layer> returnable;

	string type = "type=";
	string data = "data=";

	for (int i = 0; i < 4; i++){
		string layerData = findTag("[layer]", i);
		vector<string> layerProperties = getProperties(layerData);
		returnable.push_back(Layer());
		returnable.at(i).type=layerProperties.at(0).substr(type.length(), (layerProperties.at(0).length() - type.length()));

		for (int j = 2; j < layerProperties.size(); j++){
			vector<int> row;
			stringstream s(layerProperties.at(j));
			string numberString = "";
			
			while (getline(s, numberString, ',')){
				row.push_back(stoi(numberString));
			}
			
			returnable.at(i).layerData.push_back(row);
		}
	}

	return returnable;
}

string MapParser::findTag(string tag, int tagNum){
	string substr;
	size_t location = 0, end = 0, length = 0;
	while (tagNum >= 0){
		location = fileString.find(tag,location) + (tag.size() + 1);
		end = fileString.find("\n\n", location + 4) +1;
		length = end - location;

		tagNum--;
	}
	substr = fileString.substr(location, length);
	

	return substr;
}

vector<string> MapParser::getProperties(string tagBlock){
	int prev = 0, next = 0, length = 0;

	

	vector<string> data;

	while (next < tagBlock.length()){
		prev = next;
		next = (tagBlock.find('\n', prev + 1)) + 1;
		length = next-1 - prev;
		if (next > 0){
			data.push_back(tagBlock.substr(prev , length));
		}
		
	}


	return data;
}

MapParser::~MapParser()
{
}
