#pragma once

#include "Enemy.h"
#include "Texture.h"

class EnemyFactory
{
public:
	EnemyFactory();
	static Enemy* create(string type, Texture* texture);
	~EnemyFactory();
};

