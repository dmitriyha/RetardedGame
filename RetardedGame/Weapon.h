#pragma once
#include "Item.h"
class Weapon :
	protected Item
{
public:
	Weapon();
	~Weapon();
private:
	int strength;//strength of the weapon
};

