#pragma once

#include "../DS/Queues/LinkedQueue.h"
#include "../DS/Queues/DEndedQueue.h"

#include "../Units/AlienDrone.h"
#include "../Units/AlienMonster.h"
#include "../Units/AlienSoldier.h"
#include "Army.h"

class AlienArmy : public Army
{
private:
	DEndedQueue<AlienSoldier*> Soliders;
	AlienMonster** Monsters;
	DEndedQueue<AlienDrone*> Drones;
	int SolidersCount;
	int MonstersCount;
	int DronesCount;
	Game* GamePtr;
public:
	AlienArmy(Game* gPtr);
	// Add Alien Units
	void AddAS(AlienSoldier* unit, bool toFront = false);
	void AddAM(AlienMonster* unit);
	void AddAD(AlienDrone* unit, bool toFront = false);
	// remove Alien Units
	void RemoveAS(AlienSoldier*& unit, bool fromFront = false);
	void RemoveAM(AlienMonster*& unit);
	void RemoveAD(AlienDrone*& unit, bool fromFront = false);

	// Attack the other army
	void Attack();
	~AlienArmy();
};

