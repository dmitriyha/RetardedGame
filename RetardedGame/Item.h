#pragma once

#include <string>
using namespace std;

class Item
{
	public:
		virtual ~Item();
	protected:
		string name;//name of the item
};