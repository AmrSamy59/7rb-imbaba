#pragma once
#include"Unit.h"
class EarthGunnery:public Unit
{
private:
	bool pos = false;
public:
	EarthGunnery(Game* gPtr, int id, int Tj, float health, float power, int AC);
	bool Attack();
};

