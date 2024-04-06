#include "AlienArmy.h"

AlienArmy::AlienArmy() : Army(2000)
{

	MonstersCount = 0;

	Monsters = new AlienMonster * [1000];
	for (int i = 0; i < 1000; ++i) {
		Monsters[i] = nullptr;
	}
}


void AlienArmy::AddUnit(Unit* unit)
{
	switch (unit->getType()) {
		case Unit::AS:
		{
			Soldiers.enqueue(dynamic_cast<AlienSoldier*>(unit));
			break;
		}
		case Unit::AM:
		{
			Monsters[MonstersCount++] = dynamic_cast<AlienMonster*>(unit);
			break;
		}
		case Unit::AD:
		{
			Drones.enqueue(dynamic_cast<AlienDrone*>(unit));
			break;
		}
	}
	nextId++;
}

Unit* AlienArmy::RemoveUnit(Unit::UnitType type, bool fromBack)
{
	Unit* unit = nullptr;
	switch (type) {
		case Unit::AS:
		{
			if (Soldiers.GetCount() == 0) {
				return nullptr;
			}
			AlienSoldier* as = nullptr;
			Soldiers.dequeue(as);
			unit = as;
			break;
		}
		case Unit::AM:
		{
			if (MonstersCount == 0) {
				return nullptr;
			}
			int rand_index = std::rand() % MonstersCount;

			unit = Monsters[rand_index];
			Monsters[rand_index] = Monsters[MonstersCount - 1];
			Monsters[MonstersCount - 1] = nullptr;
			MonstersCount--;
			break;
		}
		case Unit::AD:
		{
			if (Drones.GetCount() == 0) {
				return nullptr;
			}
			AlienDrone* ad = nullptr;

			if (fromBack) {
				Drones.dequeue_back(ad);
				unit = ad;
			}
			else {
				Drones.dequeue(ad);
				unit = ad;
			}

			break;
		}
	}
	return unit;
}


void AlienArmy::Print()
{
	cout << "============================== Alien Army Alive Units ==============================" << endl;
	cout << Soldiers.GetCount() << " AS [";
	Soldiers.Print();
	cout << "] " << endl;
	cout << MonstersCount << " AM [";
	 for (int i = 0; i < MonstersCount - 1; i++) {
		 cout << Monsters[i] << ", ";
	 }
	 if(MonstersCount > 0)
		cout << Monsters[MonstersCount - 1];
	 cout << "]" << endl;
	 cout << Drones.GetCount() << " AD [";
	 Drones.Print();
	 cout << "]" << endl << endl;
	
}

void AlienArmy::Attack()
{
}



AlienArmy::~AlienArmy()
{
	delete[] Monsters;
}


