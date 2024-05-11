#include "AllyArmy.h"

AllyArmy::AllyArmy() : Army(4000)
{


}

void AllyArmy::AddUnit(Unit* unit)
{
	 /// max nuber for saver units is 250 ///

	if (unit->GetID() >= 4250) {
		delete unit;
		return;
	}
	else
	{
		SUlist.enqueue(dynamic_cast<SaverUnit*>(unit));
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

void AllyArmy::Armyretreat()
{
	SaverUnit* su = nullptr;
	while (!SUlist.isEmpty())
	{

		SUlist.dequeue(su);

	}

}



