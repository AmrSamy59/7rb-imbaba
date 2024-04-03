#pragma once

#include "../DS/Queues/LinkedQueue.h"
#include "../DS/Queues/DEndedQueue.h"

#include "../Units/AlienDrone.h"
#include "../Units/AlienMonster.h"
#include "../Units/AlienSoldier.h"

class AlienArmy
{
private:
	LinkedQueue<AlienSoldier*> Soliders;
	AlienMonster** Monsters;
	DEndedQueue<AlienDrone*> Drones;
	int SolidersCount;
	int MonstersCount;
	int DronesCount;
public:
	AlienArmy();
	// Add Alien Units
	void AddUnit(AlienSoldier* unit);
	void AddUnit(AlienMonster* unit);
	void AddUnit(AlienDrone* unit);
	// remove Alien Units
	void RemoveUnit(AlienSoldier* unit);
	void RemoveUnit(AlienMonster* unit);
	void RemoveUnit(AlienDrone* unit);
	~AlienArmy();
};

