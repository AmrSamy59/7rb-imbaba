#include "AllyArmy.h"

AllyArmy::AllyArmy() : Army(4000, 4250)
{


}

void AllyArmy::AddUnit(Unit* unit, bool newUnit)
{
	 /// max nuber for saver units is 250 ///

	if (unit->GetID() >= maxId) {
		delete unit;
		return;
	}
	else
	{
		SUlist.enqueue(dynamic_cast<SaverUnit*>(unit));
		if (newUnit)
			nextId++;
	}
		
}

Unit* AllyArmy::RemoveUnit()
{
	Unit* unit=nullptr;
	SaverUnit* su=nullptr;
	SUlist.dequeue(su);
	unit = su;
	if (unit)
		return unit;
	else
		return nullptr;
}

void AllyArmy::Print()
{
	cout << "============================== Ally Army Alive Units ==============================" << endl;
	cout << SUlist.GetCount() << " SU [";
	SUlist.Print();
	cout << "]" << endl;
}

void AllyArmy::Attack()
{
	SaverUnit* su = nullptr;
	if (SUlist.peek(su)) {
		su->Attack();
	}
}

int AllyArmy::GetArmyCount()
{
	return SUlist.GetCount() ;
}

int AllyArmy::GetUnitCount(Unit::UnitType dummy)
{
	return SUlist.GetCount();
}

bool AllyArmy::ArmyRetreat()
{
	SaverUnit* su = nullptr;
	bool retreated = false;
	while (!SUlist.isEmpty())
	{
		SUlist.dequeue(su);

		retreated = true;
	}

	return retreated;

}



