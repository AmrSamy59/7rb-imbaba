#pragma once
#include <iostream>
#include <fstream>
#include <string>
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
	void generateES();
	void generateET();
	void generateEG();
	void generateAS();
	void generateAD();
	void generateAM();
	void execute();
	void readParams();
	int randInt(int ceil, int floor); // generate random int from 0 to 100
};

