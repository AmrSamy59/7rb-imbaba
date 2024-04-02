#pragma once
#include"Unit.h"

class Earthtank:public Unit
{
public:
	static int countET;
	Earthtank();
	 void Attack(Unit*AM);
	int getcount();
	~Earthtank();
};

