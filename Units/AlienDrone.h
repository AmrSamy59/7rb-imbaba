#pragma once
#include"Unit.h"
class AlienDrone:public Unit
{
public:
	AlienDrone(Game* gPtr, int id, int Tj, float health, float power, int AC);
	bool Attack();

};

