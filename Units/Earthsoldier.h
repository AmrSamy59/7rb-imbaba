#pragma once
#include"Unit.h"
class EarthSoldier:public Unit
{
public:
	static int countES;
	EarthSoldier() ;
	 void Attack(Unit*AS) ;
	int GetCount();
	~EarthSoldier();
};

