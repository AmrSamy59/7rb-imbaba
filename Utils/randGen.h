#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "../Armies/EarthArmy.h"
#include "../Armies/AlienArmy.h"
using namespace std;
class randGen
{
private:
	EarthArmy* earthArmy;
	AlienArmy* alienArmy;
public:
	randGen(string input_file, EarthArmy* eArmy, AlienArmy* aArmy);
	void generateUnits();
	int randInt(); // generate random int from 0 to 100
};

