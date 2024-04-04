#pragma once
#include "../DS/Queues/LinkedQueue.h"
#include "../DS/Queues/DEndedQueue.h"

#include "../Units/EarthGunnery.h"
#include "../Units/EarthTank.h"
#include "../Units/EarthSoldier.h"
#include "Army.h"

class EarthArmy : public Army
{
private:
	Game* GamePtr;
public:
	EarthArmy(Game* gPtr);
	void Attack();
};

