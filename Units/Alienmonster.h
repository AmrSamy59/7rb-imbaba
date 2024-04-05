#pragma once
#include"Unit.h"

class AlienMonster:public Unit
{
public:
	AlienMonster(Game* gPtr, int id, int Tj = 0, float health = 0.0, float power = 0.0, int AC = 0);
	void Attack(Unit* ET);

};

