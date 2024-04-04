#pragma once

#include "../DS/Queues/DEndedQueue.h"

#include "../Units/AlienDrone.h"
#include "../Units/AlienMonster.h"
#include "../Units/AlienSoldier.h"
#include "Army.h"

class AlienArmy : public Army
{
private:
	DEndedQueue<AlienSoldier*> Soldiers;
	AlienMonster** Monsters;
	DEndedQueue<AlienDrone*> Drones;
	int SoldiersCount;
	int MonstersCount;
	int DronesCount;
public:
	AlienArmy();
	// Add Alien Units
	void AddAS(AlienSoldier* unit, bool toFront = false);
	void AddAM(AlienMonster* unit);
	void AddAD(AlienDrone* unit, bool toFront = false);
	// remove Alien Units
	void RemoveAS(AlienSoldier*& unit, bool fromFront = false);
	void RemoveAM(AlienMonster*& unit);
	void RemoveAD(AlienDrone*& unit, bool fromFront = false);
	void Print();
	// Attack the other army
	//void Attack();
	~AlienArmy();
};

