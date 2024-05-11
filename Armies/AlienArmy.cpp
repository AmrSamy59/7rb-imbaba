#include "AlienArmy.h"

AlienArmy::AlienArmy() : Army(2000)
{

	MonstersCount = 0;

	Monsters = new AlienMonster * [2000];
	for (int i = 0; i < 2000; ++i) {
		Monsters[i] = nullptr;
	}
}


void AlienArmy::AddUnit(Unit* unit, bool toFront)
{
	if (unit->GetID() >= 4000) {
		delete unit;
		return;
	}
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
			if (!toFront) Drones.enqueue(dynamic_cast<AlienDrone*>(unit));
			else Drones.enqueue_front(dynamic_cast<AlienDrone*>(unit));
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
	AlienSoldier* AS = nullptr;
	Unit* AM = RemoveUnit(Unit::AM);
	AlienDrone* AD1 = nullptr;// from front
	AlienDrone* AD2 = nullptr; // from back

	int EG_Pri;

	if (Soldiers.peek(AS)) {
		AS->Attack();
	}
	if (AM) {
		AM->Attack();
		AddUnit(AM);
	}

	if (Drones.peek(AD1) && Drones.peek_back(AD2)) {
		AD1->Attack();
		AD2->Attack();
	}
}

int AlienArmy::GetArmyCount()
{
	return Soldiers.GetCount() + MonstersCount + Drones.GetCount();
}

int AlienArmy::GetUnitCount(Unit::UnitType unit_type)
{
	switch (unit_type) {
	case Unit::AS:
	{
		return Soldiers.GetCount();
	}
	case Unit::AM:
	{
		return MonstersCount;
	}
	case Unit::AD:
	{
		return Drones.GetCount();
	}
	}
	return 0;
}


AlienArmy::~AlienArmy()
{
	delete[] Monsters;
}


