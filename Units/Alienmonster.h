#pragma once
#include"Unit.h"

class AlienMonster:public Unit
{
public:
	string UnitType();
	AlienMonster(Game* gPtr, int id, int Tj, float health, float power, int AC);
	void Attack(Unit* ET);

};

