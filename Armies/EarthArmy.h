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
	ArrayStack<HealingUnit*>Healinglist;
	int InfectedCount;
	int TotalInfectedCount;
public:
	EarthArmy();

	~EarthArmy();
	void AddUnit(Unit* unit, bool newUnit=false);
	// remove Add Units
	void AddUnit(Unit* unit, bool newUnit=false);
	// remove Earth Units
	Unit* RemoveUnit(Unit::UnitType type);
	
	void Print();
	void Attack();
	int GetArmyCount();
	int GetUnitCount(Unit::UnitType unit_type);
	int GetInfectedCount();
	void SpreadInfection();
	void AddInfectedCountTotal();
	int GetTotalInfectedCount();
};

