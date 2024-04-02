#pragma once
#include"Unit.h"

class Alienmonster:public Unit
{
	
public:
	static int countAM;
	Alienmonster();
	 void Attack(Unit* ET);
	 int getcount()const;
	 ~Alienmonster();
};

