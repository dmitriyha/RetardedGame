#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "MapHeader.h"
#include "TileSet.h"
#include "Layer.h"
using namespace std;

class MapParser{
	string fileString;
	MapHeader header;
public:
	MapParser();
	void readFile(string name);
	MapHeader getMapHeader();
	vector<TileSet> getTilesetData();
	vector<Layer> MapParser::getLayers();
	~MapParser();
private:
	string findTag(string tag, int tagNum = 0);
	vector<string> getProperties(string tagBlock);
};

