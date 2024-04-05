#pragma once

#include "Units/Unit.h"
#include "DS/Queues/LinkedQueue.h"
#include "Armies/EarthArmy.h"
#include "Armies/AlienArmy.h"
#include "Armies/AlienArmyParams.h"
#include "Armies/EarthArmyParams.h"
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
	void addEs_Unit(int pow, int health, int Cap);
	void addEt_Unit(int pow, int health, int Cap);
	void addEg_Unit(int pow, int health, int Cap);
	void addAs_Unit(int pow, int health, int Cap);
	void addAd_Unit(int pow, int health, int Cap);
	void addAm_Unit(int pow, int health, int Cap);
	void loadFile(int& N, int& Prob,EarthArmyParams* eParams, AlienArmyParams* aParams);
	~Game();
};