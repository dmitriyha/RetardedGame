#pragma once
#include "Weapon.h"
class Gun :
	private Weapon
{
public:
	Gun();
	~Gun();
private:
	int bullets;//amount of bullets
};

