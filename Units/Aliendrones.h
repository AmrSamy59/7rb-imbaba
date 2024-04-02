#pragma once
#include"Unit.h"
class Aliendrones:public Unit
{
public:
	static int countAD;
	Aliendrones();
	 void Attack(Unit* EG);
	 int getcount()const;
	 ~Aliendrones();
};

