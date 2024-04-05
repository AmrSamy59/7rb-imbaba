#pragma once
#include"Unit.h"
class EarthSoldier:public Unit
{
public:
	EarthSoldier(Game* gPtr, int id, int Tj, float health, float power, int AC) ;
	 void Attack(Unit*AS) ;

};

