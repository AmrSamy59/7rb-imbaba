#pragma once
#include"Unit.h"
class AlienDrone:public Unit
{
public:
	
	AlienDrone();
	 void Attack(Unit* EG);
	 string UnitType();

};

