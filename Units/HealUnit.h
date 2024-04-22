#pragma once
#include"Unit.h"
class HealUnit:public Unit
{
public:
	HealUnit(Game* gPtr, int id, int Tj, float health, float power, int AC) ;
	 void Heal(Unit*AS) ; //Modify this Osta

};