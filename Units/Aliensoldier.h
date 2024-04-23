#pragma once
#include"Unit.h"
class AlienSoldier:public Unit
{
public:
	AlienSoldier(Game* gPtr, int id, int Tj, float health, float power, int AC);
	bool Attack(Unit* ES);
	

};

