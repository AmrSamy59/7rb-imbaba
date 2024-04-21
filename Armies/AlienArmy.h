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
public:
	AlienArmy();
	// Add Alien Units
	void AddUnit(Unit* unit);
	// remove Alien Units
	Unit* RemoveUnit(Unit::UnitType type, bool fromBack = false);
	
	void Print();
	// Attack the other army
	void Attack();
	~AlienArmy();
};

