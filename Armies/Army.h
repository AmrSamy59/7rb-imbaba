#pragma once
//#include"../../Units/Unit.h"
class Army
{
protected:
	int nextId;
	int maxId;
public:
	Army(int startingId = 0, int max_id = 0) { nextId = startingId; maxId = max_id; };
	int getNextUnitId() { return nextId; };
	virtual void Attack() = 0;
	virtual int GetArmyCount() = 0;
	virtual int GetUnitCount(Unit::UnitType unit_type) = 0;
};

