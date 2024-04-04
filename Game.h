#pragma once

#include "Units/Unit.h"
#include "DS/Queues/LinkedQueue.h"
#include "Armies/EarthArmy.h"
#include "Armies/AlienArmy.h"
#include "Utils/randGen.h"

class Game
{
private:
	LinkedQueue<Unit*> Temp;
	LinkedQueue<Unit*> Killed;
	EarthArmy* earthArmy;
	AlienArmy* alienArmy;
	randGen* randGenerator;
	char mode; // 's' silence, 'a' active
	int timeStep;
public:
	Game(char _mode ='a');
	void NextTimeStep();
};