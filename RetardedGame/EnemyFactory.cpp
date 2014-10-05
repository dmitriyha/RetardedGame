#include "EnemyFactory.h"


EnemyFactory::EnemyFactory()
{
}

Enemy* EnemyFactory::create(string type, Texture* texture){
	if (type == "enemy"){//example factory method. 
		Enemy* e = new Enemy();//when further enemy classes are created, returen those instead
		e->setTexturePointer(texture);//set the texture pointer
		return e;
	}
	else{
		return NULL;
	}
}

EnemyFactory::~EnemyFactory()
{
}
