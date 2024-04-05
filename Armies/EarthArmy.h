#pragma once
#include "../DS/Queues/DEndedQueue.h"
#include"..\DS\Stacks\ArrayStack.h"
#include"..\DS\PriorityQueue\priQueue.h"
#include "../Units/EarthGunnery.h"
#include "../Units/EarthTank.h"
#include "../Units/EarthSoldier.h"
#include "Army.h"

class EarthArmy : public Army
{
private:
	DEndedQueue< EarthSoldier*>Soldiers;
	ArrayStack< EarthTank*>Tanks;
	priQueue< EarthGunnery*>Gunneries;
	int SoldierCount;
	int TankCount;
	int GunneryCount;
public:
	EarthArmy();
	void AddES(EarthSoldier* Unit, bool toFront = false);
	void AddET(EarthTank* Unit);
	void AddEG(EarthGunnery* Unit);
	void RemoveES(EarthSoldier*& unit, bool fromFront = false);
	void RemoveET(EarthTank*& unit);
	void RemoveEG(EarthGunnery*& unit);
	void Print();
	
	void Attack();

	~EarthArmy();
	//void Attack();
};

