#pragma once

#include "Item.h"
class Gadget :
	protected Item
{
public:
	virtual void render();
	~Gadget();
};
