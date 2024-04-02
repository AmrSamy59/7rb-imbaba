#pragma once
#include"Unit.h"
class Aliensoldier:public Unit
{
public:
	static int countAS;
	Aliensoldier();
	 void Attack(Unit* ES);
	int getcount();
	~Aliensoldier();

};

