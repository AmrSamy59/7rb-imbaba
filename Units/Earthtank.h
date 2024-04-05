#pragma once
#include"Unit.h"

class EarthTank:public Unit
{
public:
	
	EarthTank(Game* gPtr, int id, int Tj = 0, float health = 0.0, float power = 0.0, int AC = 0);
	 void Attack(Unit*AM);
	
};

