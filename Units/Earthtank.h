#pragma once
#include"Unit.h"

class EarthTank:public Unit
{
public:
	static int countET;
	EarthTank();
	 void Attack(Unit*AM);
	int GetCount();
	~EarthTank();
};

