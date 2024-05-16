#pragma once

#include "../DS/Queues/DEndedQueue.h"
#include "../DS/Queues/LinkedQueue.h"
#include "../Units/AlienDrone.h"
#include "../Units/AlienMonster.h"
#include "../Units/AlienSoldier.h"
#include "Army.h"

class AlienArmy : public Army
{
private:
	LinkedQueue<AlienSoldier*> Soldiers;
	AlienMonster** Monsters;
	DEndedQueue<AlienDrone*> Drones;
	int MonstersCount;
	double infectionProb;
public:
	AlienArmy();
	~AlienArmy();
	// Add Alien Units
	void AddUnit(Unit* unit, bool toFront = false, bool newUnit = false);
	// remove Alien Units
	Unit* RemoveUnit(Unit::UnitType type, bool fromBack = false);

	void SetInfectionProb(double prob);
	double GetInfectionProb();
	
	void Print();
	// Attack the other army
	void Attack();

	int GetArmyCount();
	int GetUnitCount(Unit::UnitType unit_type);
};

