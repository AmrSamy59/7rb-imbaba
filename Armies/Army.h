#pragma once
class Army
{
protected:
	int nextId;
public:
	Army(int startingId = 0) { nextId = startingId; };
	int getNextUnitId() { return nextId; };
	virtual void Attack() = 0;
};

