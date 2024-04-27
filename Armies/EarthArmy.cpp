#include "EarthArmy.h"
#include"../Game.h"
EarthArmy::EarthArmy() : Army(1)
{}

void EarthArmy::AddUnit(Unit* unit)
{
	switch (unit->getType()) {
		case Unit::ES:
		{
			Soldiers.enqueue(dynamic_cast<EarthSoldier*>(unit));
			break;
		}
		case Unit::ET:
		{
			Tanks.push(dynamic_cast<EarthTank*>(unit));
			break;
		}
		case Unit::EG:
		{
			int pri = unit->GetHealth() + unit->GetPower();
			Gunneries.enqueue(dynamic_cast<EarthGunnery*>(unit), pri);
			break;
		}
		case Unit::HU:
		{
			Healinglist.push(dynamic_cast<HealingUnit*>(unit));
			break;
		}
	}
	nextId++;
}

Unit* EarthArmy::RemoveUnit(Unit::UnitType type)
{
	Unit* unit = nullptr;
	switch (type) {
		case Unit::ES:
		{
			if (Soldiers.GetCount() == 0) {
				return nullptr;
			}
			EarthSoldier* es = nullptr;
			Soldiers.dequeue(es);
			unit = es;
			break;
		}
		case Unit::ET:
		{
			if (Tanks.GetCount() == 0) {
				return nullptr;
			}
			EarthTank* et = nullptr;
			Tanks.pop(et);
			unit = et;
			break;
		}
		case Unit::EG:
		{
			if (Gunneries.GetCount() == 0) {
				return nullptr;
			}
			EarthGunnery* eg = nullptr;
			int pri = 0;
			Gunneries.dequeue(eg, pri);
			unit = eg;
			break;
		}
		case Unit::HU:
		{
			if (Healinglist.GetCount() == 0) {
				return nullptr;
			}
			HealingUnit* hu = nullptr;
			Healinglist.pop(hu);
			unit = hu;
			break;
		}
	}
	return unit;
}


void EarthArmy::Print()
{
	cout << "============================== Earth Army Alive Units ==============================" << endl;
	cout << Soldiers.GetCount() << " ES [";
	Soldiers.Print();
	cout << "]" << endl;
	cout << Tanks.GetCount() << " ET [";
	Tanks.Print();
	cout << "]" << endl;
	cout << Gunneries.GetCount() << " EG [";
	Gunneries.Print();
	cout << "]" << endl;
	cout << Healinglist.GetCount() << " HU [";
	Healinglist.Print();
	cout << "]" << endl << endl;
}
EarthArmy::~EarthArmy()
{
}

void EarthArmy::Attack()
{
	//Game* gptr =gptr->GetGamePtr();
	//ptr->AddToKilledList(this); /// make in the earth army attack pop from stack killed your self
	EarthSoldier* ES = nullptr;
	EarthTank* ET = nullptr;
	EarthGunnery* EG = nullptr;
	HealingUnit* HU = nullptr;
	int EG_Pri;

	if (Soldiers.peek(ES)) {
		ES->Attack();
	}

	if (Tanks.peek(ET)) {
		///ET->Attack();
	}

	if (Gunneries.peek(EG, EG_Pri)) {
		EG->Attack();
	}

	if (Healinglist.peek(HU)) {
		HU->Attack();
	}
}

int EarthArmy::GetArmyCount()
{
	return Soldiers.GetCount() + Tanks.GetCount() + Gunneries.GetCount();
}

int EarthArmy::GetUnitCount(Unit::UnitType unit_type)
{
	switch (unit_type) {
		case Unit::ES:
		{
			return Soldiers.GetCount();
		}
		case Unit::ET:
		{
			return Tanks.GetCount();
		}
		case Unit::EG:
		{
			return Gunneries.GetCount();
		}
		case Unit::HU:
		{
			return Healinglist.GetCount();
		}
	}
	return 0;
}

