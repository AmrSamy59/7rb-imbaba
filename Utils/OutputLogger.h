#pragma once
#include <fstream>
#include <string>

#include "../Game.h"
using namespace std;

class OutputLogger
{
private:
	string file_name;
	ofstream File;
	Game* gptr;
	int earthDf;
	int earthDd;
	int earthDb;
	int alienDf;
	int alienDd;
	int alienDb;
	int saverDf;
	int saverDd;
	int saverDb;
public:
	OutputLogger(string fname, Game* gamePtr);
	void LogUnit(Unit* unit);
	void LogEarthArmy(EarthArmy* army);
	void LogAlienArmy(AlienArmy* army);

	void LogGameStatus();

	~OutputLogger();
};

