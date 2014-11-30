#pragma once
#include <string>
#include <vector>

struct Layer{
	std::string type;
	std::vector<std::vector<int>> layerData;
};