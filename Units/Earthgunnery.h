#pragma once
#include"Unit.h"
class EarthGunnery:public Unit
{
public:
	static int countEG;
	EarthGunnery();
	 void Attack(Unit*AD);
	int GetCount();
	~EarthGunnery();
};

