#pragma once
#include"Unit.h"
class Earthgunnery:public Unit
{
public:
	static int countEG;
	Earthgunnery();
	 void Attack(Unit*AD);
	int getcount();
	~Earthgunnery();
};

