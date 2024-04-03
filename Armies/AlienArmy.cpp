#include "AlienArmy.h"

AlienArmy::AlienArmy()
{
	SolidersCount = MonstersCount = DronesCount = 0;

	Monsters = new AlienMonster * [1000];
	for (int i = 0; i < 1000; ++i) {
		Monsters[i] = nullptr;
	}
}

void AlienArmy::AddUnit(AlienSoldier* unit)
{
	Soliders.enqueue(unit);
}

void AlienArmy::AddUnit(AlienMonster* unit)
{
	Monsters[MonstersCount++] = unit;
}

void AlienArmy::AddUnit(AlienDrone* unit)
{
	Drones.enqueue(unit);
}

void AlienArmy::RemoveUnit(AlienSoldier* unit)
{
	Soliders.dequeue(unit);
}

void AlienArmy::RemoveUnit(AlienMonster* unit)
{
}

void AlienArmy::RemoveUnit(AlienDrone* unit)
{
	Drones.dequeue(unit);
}

AlienArmy::~AlienArmy()
{
	delete[] Monsters;
}


