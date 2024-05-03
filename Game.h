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
	char mode; // 's' silence, 'i' interactive
	int game_status; // 0 ongoing, 1 earth won, -1 aliens won, 2 tie
	string file;
	int timeStep;
public:
	Game(char _mode ='i');
	char GetGameMode();
	int checkGameStatus();
	void NextTimeStep();
	void NextTimeStepTest();
	int GetCurrentTimeStep()const;
	//These getters for telling randgen which Id and Tj to generate Unit with
	int getNextUnitId(char army);
	int getTj();
	Game* GetGamePtr();
	/////////////////////////////////////////////////////////////
	bool canArmiesAttack();
	double GetRatio();
	void addUnit(Unit* unit);
	void AddToKilledList(Unit* unit);
	Unit* pickAlienunit(Unit::UnitType type, bool fromBack = false);
	void  ReturnAlienUnit(Unit* r);
	Unit* PickEarthUnit(Unit::UnitType type);
	void  ReturnEarthUnit(Unit* r);
	//////////////////////////////////
	Unit* GetFromUML();
	void AddToUML(Unit* unit);
	void CheckingUML();
	void ReturnToUML(Unit* unit);
	///////////////////////////////////
	void PrintKilledList();
	void PrintUML();
	void loadFile(int& N, int& Prob,EarthArmyConfig* eParams, AlienArmyConfig* aParams);
	~Game();
};