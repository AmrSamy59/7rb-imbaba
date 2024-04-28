#pragma once
#include"Unit.h"
class HealingUnit:public Unit
{
public:
	HealingUnit(Game* gPtr, int id, int Tj, float health, float power, int AC);
	bool Attack();
};

