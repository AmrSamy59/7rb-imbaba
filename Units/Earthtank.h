#pragma once
#include"Unit.h"

class EarthTank:public Unit
{
public:
	
	EarthTank(Game* gPtr, int id, int Tj, float health, float power, int AC);
	 void Attack(Unit*AM);
	 string UnitType();
	
};

