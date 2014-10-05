#pragma once
#include "Item.h"
class Weapon :
	protected Item
{
public:
	Weapon();
	virtual void render();
	~Weapon();
private:
	int strength;//strength of the weapon
};

