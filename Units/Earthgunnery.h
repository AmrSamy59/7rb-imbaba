#pragma once
#include"Unit.h"
class EarthGunnery:public Unit
{
public:
	EarthGunnery(Game* gPtr, int id, int Tj, float health, float power, int AC);
	 void Attack(Unit*AD);
};

