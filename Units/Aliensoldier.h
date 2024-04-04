#pragma once
#include"Unit.h"
class AlienSoldier:public Unit
{
public:
	string UnitType();
	AlienSoldier();
	 void Attack(Unit* ES);
	

};

