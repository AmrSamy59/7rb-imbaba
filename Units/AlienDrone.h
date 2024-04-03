#pragma once
#include"Unit.h"
class AlienDrone:public Unit
{
public:
	static int countAD;
	AlienDrone();
	 void Attack(Unit* EG);
	 int GetCount()const;
	 ~AlienDrone();
};

