#pragma once

#include "Units/Unit.h"
#include "DS/Queues/LinkedQueue.h"
#include"DS/PriorityQueue/priQueue.h"
#include "Armies/EarthArmy.h"
#include "Armies/AlienArmy.h"
#include "Armies/AlienArmyConfig.h"
#include "Armies/EarthArmyConfig.h"
#include "Utils/randGen.h"
#include <string>
#include <fstream>
class randGen;

class Game
{
private:
	LinkedQueue<Unit*> Killed;
	priQueue<Unit*> UML;
	EarthArmy* earthArmy;
	AlienArmy* alienArmy;
	randGen* randGenerator;
	char mode; // 's' silence, 'a' active
	string file;
	int timeStep;
public:
	Game(char _mode ='a');
	void NextTimeStep();
	void NextTimeStepTest();
	int GetCurrentTimeStep()const;
	//These getters for telling randgen which Id and Tj to generate Unit with
	int getNextUnitId(char army);
	int getTj();
	/////////////////////////////////////////////////////////////
	void addUnit(Unit* unit);
	void AddToKilledList(Unit* unit);
	//////////////////////////////////
	Unit* GetFromUML();
	void AddToUML(Unit* unit);
	void CheckingUML();

	///////////////////////////////////
	void PrintKilledList();
	void loadFile(int& N, int& Prob,EarthArmyConfig* eParams, AlienArmyConfig* aParams);
	~Game();
};