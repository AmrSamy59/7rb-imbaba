#include "EarthArmy.h"

EarthArmy::EarthArmy() : Army(1)
{
	 SoldierCount=0;
	 TankCount=0;
	 GunneryCount=0;
}

void EarthArmy::AddES(EarthSoldier* Unit, bool toFront)
{
	if (toFront)
		Soldiers.enqueue_front(Unit);
	else
	Soldiers.enqueue(Unit);
	SoldierCount++;
	nextId++;
}

void EarthArmy::AddET(EarthTank* Unit)
{
	Tanks.push(Unit);
	TankCount++;
	nextId++;
}

void EarthArmy::AddEG(EarthGunnery* Unit)
{
	int pri = Unit->GetHealth() + Unit->GetPower();
	Gunneries.enqueue(Unit,pri);
	GunneryCount++;
	nextId++;
}

void EarthArmy::RemoveES(EarthSoldier*& Unit, bool fromFront)
{
	// from front ==true --> dequeue front
	if (fromFront)
		Soldiers.dequeue(Unit);
	else
		Soldiers.dequeue_back(Unit);
	SoldierCount--;

}

void EarthArmy::RemoveET(EarthTank*& Unit)
{
	Tanks.pop(Unit);
	TankCount--;

}

void EarthArmy::RemoveEG(EarthGunnery*& unit)
{
	int pri = 0;
	Gunneries.dequeue(unit, pri);
	GunneryCount--;
}
void EarthArmy::Print()
{
	cout << "============================== Earth Army Alive Units ==============================" << endl;
	cout << SoldierCount << " ES [";
	Soldiers.Print();
	cout << " ] " << endl;
	cout << TankCount << " ET [";
	Tanks.Print();
	cout << " ] " << endl;
	cout << GunneryCount << " EG [";
	Gunneries.Print();
	cout << " ] " << endl;
}
EarthArmy::~EarthArmy()
{
}

void EarthArmy::Attack()
{
}

