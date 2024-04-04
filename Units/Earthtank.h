#pragma once
#include"Unit.h"

class EarthTank:public Unit
{
public:
	
	EarthTank();
	 void Attack(Unit*AM);
	 string UnitType();
	
};

