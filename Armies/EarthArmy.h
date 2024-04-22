#pragma once
#include "../DS/Queues/LinkedQueue.h"
#include"../DS/Stacks/ArrayStack.h"
#include"../DS/PriorityQueue/priQueue.h"
#include "../Units/EarthGunnery.h"
#include "../Units/EarthTank.h"
#include "../Units/EarthSoldier.h"
#include"../Units/HealingUnit.h"
#include "Army.h"

class EarthArmy : public Army
{
private:
	LinkedQueue<EarthSoldier*>Soldiers;
	ArrayStack<EarthTank*>Tanks;
	priQueue<EarthGunnery*>Gunneries;
	ArrayStack<HealingUnit*>Healing;
public:
	EarthArmy();
	// remove Add Units
	void AddUnit(Unit* unit);
	// remove Earth Units
	Unit* RemoveUnit(Unit::UnitType type);
	
	void Print();
	void Attack();

	~EarthArmy();
	
};

