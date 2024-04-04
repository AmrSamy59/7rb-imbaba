#pragma once
#include"Unit.h"
class EarthSoldier:public Unit
{
public:
	string UnitType();
	EarthSoldier() ;
	 void Attack(Unit*AS) ;

};

