#pragma once
#include "../DS/Queues/LinkedQueue.h"
#include "../Units/SaverUnit.h"
#include "Army.h"



class AllyArmy : public Army
{
private:
	LinkedQueue<SaverUnit*>SUlist;
	
public:
	AllyArmy();
	void AddUnit(Unit* unit, bool newUnit = false);
	// remove Ally Units
	Unit* RemoveUnit();

	void Print();
	void Attack();
	int GetArmyCount();
	int GetUnitCount(Unit::UnitType unit_type);
	bool ArmyRetreat();

};


