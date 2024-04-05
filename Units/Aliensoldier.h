#pragma once
#include"Unit.h"
class AlienSoldier:public Unit
{
public:
	string UnitType();
	AlienSoldier(Game* gPtr, int id, int Tj, float health, float power, int AC);
	 void Attack(Unit* ES);
	

};

