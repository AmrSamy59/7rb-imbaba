#pragma once
#include"Unit.h"
class Earthsoldier:public Unit
{
public:
	static int countES;
	Earthsoldier() ;
	 void Attack(Unit*AS) ;
	int getcount();
	~Earthsoldier();
};

