#pragma once
#include"Unit.h"

class AlienMonster:public Unit
{
public:
	AlienMonster(Game* gPtr, int id, int Tj, float health, float power, int AC);
	bool Attack();

};

