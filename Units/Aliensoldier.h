#pragma once
#include"Unit.h"
class AlienSoldier:public Unit
{
public:
	static int countAS;
	AlienSoldier();
	 void Attack(Unit* ES);
	int GetCount();
	~AlienSoldier();

};

