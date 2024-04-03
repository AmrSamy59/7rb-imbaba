#pragma once
#include"Unit.h"

class AlienMonster:public Unit
{
	
public:
	static int countAM;
	AlienMonster();
	 void Attack(Unit* ET);
	 int GetCount()const;
	 ~AlienMonster();
};

