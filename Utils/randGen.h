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
	int N, Prob, ES, ET, EG,EsC,EtC,EgC;
public:
	randGen(Game*);
	void generateUnits(int,int,int);
	void execute(int,int,int,int,int);
	int randInt(int ceil, int floor); // generate random int from 0 to 100
};

