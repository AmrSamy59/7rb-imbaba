#pragma once
#include"Unit.h"
class HealingUnit:public Unit
{
	HealingUnit(Game* gPtr, int id, int Tj, float health, float power, int AC);
	void Attack(Unit* dummy);
};

