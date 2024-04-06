#pragma once
#include <iostream>
#include "../Game.h"

using namespace std;
class randGen
{
private:
	Game* pGame;
	EarthArmyConfig* eParams;
	AlienArmyConfig* aParams;
	int N, Prob;
public:
	randGen(Game*);
	void generateUnit(Unit::UnitType UnitType);
	void execute();
	void readParams();
	int randInt(int ceil, int floor); // generate random int from 0 to 100
};

