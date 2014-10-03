#pragma once
#include "Character.h"
class Enemy : public Character
{
public:
	Enemy();
	void move();//when more enemy types are added, make virtual, cos this will be the place for AI
	virtual ~Enemy();
};
