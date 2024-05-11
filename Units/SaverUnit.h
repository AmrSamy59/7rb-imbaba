#pragma once
#include"Unit.h"
class SaverUnit:public Unit
{
public:
	SaverUnit(Game* gPtr, int id, int Tj, float health, float power, int AC);
	bool Attack();



};

