#pragma once
#include"Unit.h"
class EarthGunnery:public Unit
{
public:
	string UnitType();
	EarthGunnery();
	 void Attack(Unit*AD);
};

