#include "EarthArmy.h"
#include"../Game.h"
EarthArmy::EarthArmy() : Army(1, 1000)
{
	InfectedCount = 0;
	TotalInfectedCount = 0;
}

void EarthArmy::AddUnit(Unit* unit, bool newUnit)
{
	if (unit->GetID() >= maxId) {
		delete unit;
		return;
	}
	switch (unit->getType()) {
		case Unit::ES:
		{
			Soldiers.enqueue(dynamic_cast<EarthSoldier*>(unit));
			if(unit->IsInfected())
				InfectedCount++;
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
	if (newUnit)
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
			if(unit->IsInfected())
				InfectedCount--;
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
	float infRatio = 0;
	if(Soldiers.GetCount() != 0)
		infRatio = float(InfectedCount * 100) / Soldiers.GetCount();
	cout << "============================== Earth Army Alive Units ==============================" << endl;
	cout << Soldiers.GetCount() << " ES [";
	Soldiers.Print();
	cout << "]" << endl;
	cout << "Total Infected: " << InfectedCount << " Infected Ratio: " << infRatio << "%" << endl;
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
	Unit* ES = RemoveUnit(Unit::ES);
	EarthTank* ET = nullptr;
	EarthGunnery* EG = nullptr;
	HealingUnit* HU = nullptr;
	int EG_Pri;

	if (ES) {
		ES->Attack();
		AddUnit(ES);
	}

	if (Tanks.peek(ET)) {
		ET->Attack();
	}

	if (Gunneries.peek(EG, EG_Pri)) {
		EG->Attack();
	}

	if (Healinglist.peek(HU)) {
		if (HU->Attack())
			Healinglist.pop(HU);
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

int EarthArmy::GetInfectedCount()
{
	return InfectedCount;
}

void EarthArmy::SpreadInfection()
{
	if(InfectedCount == 0)
		return;

	EarthSoldier* ES = nullptr;
	int count = Soldiers.GetCount();
	double prob = rand() % 100;
	if (InfectedCount < count && prob <= 2)
	{
		int random = rand() % (count);
		bool infected = false;
		for (int i = 0; i < count; i++)
		{
			Soldiers.dequeue(ES);
			if (!ES->IsInfected() && !infected)
			{
				if (i >= random)
				{
					ES->SetInfected(true);
					InfectedCount++;
					TotalInfectedCount++;
					infected = true;
					ES->PrintStatus("Got infected by another infected solider!");
				}
			}
			Soldiers.enqueue(ES);
		}
		
	}

}

void EarthArmy::AddInfectedCountTotal()
{
	++TotalInfectedCount;
}

int EarthArmy::GetTotalInfectedCount()
{
	return TotalInfectedCount;
}
