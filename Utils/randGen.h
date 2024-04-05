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
	int N, Prob, ES, ET, EG, AS, AD, AM,
		ePowCeil, ePowFloor, eHealCeil, eHealFloor, eCapCeil, eCapFloor,
		aPowCeil, aPowFloor, aHealCeil, aHealFloor, aCapCeil, aCapFloor,
		EsC, EtC, EgC, AsC, AmC, AdC;
public:
	randGen(Game*);
	void generateUnits(int,int,int, int, int, int);
	void execute();
	void readParams();
	int randInt(int ceil, int floor); // generate random int from 0 to 100
};

