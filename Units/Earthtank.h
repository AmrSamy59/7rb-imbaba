#pragma once
#include"Unit.h"

class EarthTank:public Unit
{
	private:
		bool AttackAS = false;
	public:
	
	EarthTank(Game* gPtr, int id, int Tj, float health, float power, int AC);
	bool Attack();
	
};

