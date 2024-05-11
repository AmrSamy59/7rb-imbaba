#pragma once
//#include"../../Units/Unit.h"
class Army
{
protected:
	int nextId;
public:
	Army(int startingId = 0) { nextId = startingId; };
	int getNextUnitId() { return nextId; };
	virtual void Attack() = 0;
	virtual int GetArmyCount() = 0;
	virtual int GetUnitCount(Unit::UnitType unit_type) = 0;
};

