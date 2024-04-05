#include "AlienArmy.h"

AlienArmy::AlienArmy() : Army(2000)
{

	SoldiersCount = MonstersCount = DronesCount = 0;

	Monsters = new AlienMonster * [1000];
	for (int i = 0; i < 1000; ++i) {
		Monsters[i] = nullptr;
	}
}

void AlienArmy::AddAS(AlienSoldier* unit)
{
	Soldiers.enqueue(unit);
	SoldiersCount++;
	nextId++;
}

void AlienArmy::AddAM(AlienMonster* unit)
{
	Monsters[MonstersCount++] = unit;
	nextId++;
}

void AlienArmy::AddAD(AlienDrone* unit, bool toFront)
{
	if (toFront)
		Drones.enqueue_front(unit);
	else
		Drones.enqueue(unit);
	DronesCount++;
	nextId++;
}

void AlienArmy::RemoveAS(AlienSoldier*& unit, bool fromFront)
{
	Soldiers.dequeue(unit);
	SoldiersCount--;
}

void AlienArmy::RemoveAM(AlienMonster*& unit) // please rag3
{
	int rand_index = std::rand() %  MonstersCount ;
	
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
void AlienArmy::Print()
{
	cout << "============================== Alien Army Alive Units ==============================" << endl;
	cout << SoldiersCount << " AS [";
	Soldiers.Print();
	cout << " ] " << endl;
	cout << MonstersCount << " AM [";
	 for (int i = 0; i < MonstersCount - 1; i++) {
		 cout << Monsters[i] << " , ";
	 }
	 cout << Monsters[MonstersCount - 1];
	 cout << " ] " << endl;
	 cout << DronesCount << " AD [";
	 Drones.Print();
	 cout << " ] " << endl;
	
}

void AlienArmy::Attack()
{
}



AlienArmy::~AlienArmy()
{
	delete[] Monsters;
}


