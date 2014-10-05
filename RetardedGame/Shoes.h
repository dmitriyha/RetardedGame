#pragma once
#include "Gadget.h"
class Shoes :
	protected Gadget
{
public:
	Shoes();
	~Shoes();
private:
	int slowRate;//how much it slows down the character when falling
};

