#pragma once
#include"Unit.h"

class AlienMonster:public Unit
{
public:
	string UnitType();
	AlienMonster();
	void Attack(Unit* ET);

};

