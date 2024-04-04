#include "AlienArmy.h"

AlienArmy::AlienArmy(Game* gPtr)
{
	GamePtr = gPtr;

	SolidersCount = MonstersCount = DronesCount = 0;

	Monsters = new AlienMonster * [1000];
	for (int i = 0; i < 1000; ++i) {
		Monsters[i] = nullptr;
	}
}

void AlienArmy::AddAS(AlienSoldier* unit, bool toFront)
{
	if (toFront)
		Soliders.enqueue_front(unit);
	else
		Soliders.enqueue(unit);
	SolidersCount++;
}

void AlienArmy::AddAM(AlienMonster* unit)
{
	Monsters[MonstersCount++] = unit;
}

void AlienArmy::AddAD(AlienDrone* unit, bool toFront)
{
	if (toFront)
		Drones.enqueue_front(unit);
	else
		Drones.enqueue(unit);
	DronesCount++;
}

void AlienArmy::RemoveAS(AlienSoldier*& unit, bool fromFront)
{
	Soliders.dequeue(unit);
	SolidersCount--;
}

void AlienArmy::RemoveAM(AlienMonster*& unit) // please rag3
{
	int rand_index = 0;
	
	unit = Monsters[rand_index];
	Monsters[rand_index] = nullptr;

	for (int i = rand_index + 1; i < MonstersCount; ++i) {
		Monsters[i - 1] = Monsters[i];
	}
	MonstersCount--;
}

void AlienArmy::RemoveAD(AlienDrone*& unit, bool fromFront)
{
	Drones.dequeue(unit);
	DronesCount--;
}

void AlienArmy::Attack()
{

}

AlienArmy::~AlienArmy()
{
	delete[] Monsters;
}


