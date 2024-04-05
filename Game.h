#pragma once

#include "Units/Unit.h"
#include "DS/Queues/LinkedQueue.h"
#include "Armies/EarthArmy.h"
#include "Armies/AlienArmy.h"
#include "Units/EarthSoldier.h"
#include "Units/EarthTank.h"
#include "Units/EarthGunnery.h"
#include "Utils/randGen.h"
#include <string>
#include <fstream>
class randGen;
class Game
{
private:
	LinkedQueue<Unit*> Temp;
	LinkedQueue<Unit*> Killed;
	EarthArmy* earthArmy;
	AlienArmy* alienArmy;
	randGen* randGenerator;
	char mode; // 's' silence, 'a' active
	string file;
	int timeStep;
public:
	Game(char _mode ='a');
	void NextTimeStep();
	void addEarthUnits(int, int, int);
	void addAlienUnits(int, int, int);
	void loadFile(int& N, int& Prob, int& ES, int& EG, int& ET, int& AS, int& AD, int& AM,
		int& ePowRangeCeil,
		int& ePowRangeFloor,
		int& eHealRangeCeil,
		int& eHealRangeFloor,
		int& eAttackCapCeil,
		int& eAttackCapFloor,
		int& aPowRangeCeil,
		int& aPowRangeFloor,
		int& aHealRangeCeil,
		int& aHealRangeFloor,
		int& aAttackCapCeil,
		int& aAttackCapFloor);
	~Game();
};