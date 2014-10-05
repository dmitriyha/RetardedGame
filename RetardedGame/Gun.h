#pragma once
#include "Weapon.h"
class Gun :
	private Weapon
{
public:
	Gun();
	void render();
	~Gun();
private:
	int bullets;//amount of bullets
};

