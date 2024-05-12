#pragma once

#include "Units/Unit.h"
#include "DS/Queues/LinkedQueue.h"
#include"DS/PriorityQueue/priQueue.h"
#include "Armies/EarthArmy.h"
#include "Armies/AlienArmy.h"
#include"Armies/AllyArmy.h"
#include "Armies/AlienArmyConfig.h"
#include "Armies/EarthArmyConfig.h"
#include"Armies/AllyArmyConfig.h"
#include "Utils/randGen.h"
#include "Utils/OutputLogger.h"
#include <string>
#include <fstream>
class randGen;
class OutputLogger;

class Game
{
private:
	LinkedQueue<Unit*> Killed;
	priQueue<Unit*> UML;
	EarthArmy* earthArmy;
	AlienArmy* alienArmy;
	AllyArmy* allyArmy;
	randGen* randGenerator;
	OutputLogger* logger;
	char mode; // 's' silence, 'i' interactive
	int game_status; // 0 ongoing, 1 earth won, -1 aliens won, 2 tie
	string file;
	int timeStep;
	bool ETapproval = false;
	int HealedUnitCount = 0;
	int DestructedUnitsCount[Unit::LastType];
public:
	Game(char _mode ='i');
	void PlayGame(char game_mode);
	void LogGameResult();
	char GetGameMode();
	int checkGameStatus();
	void NextTimeStep();

	int GetCurrentTimeStep()const;
	//These getters for telling randgen which Id and Tj to generate Unit with
	int getNextUnitId(char army);
	int getTj();
	Game* GetGamePtr();
	/////////////////////////////////////////////////////////////
	bool canArmiesAttack();
	bool CanEtAttackAs();
	double GetRatio();
	void addUnit(Unit* unit, bool newUnit=false);
	void AddToKilledList(Unit* unit);
	int GetDestructedUnitCount(Unit::UnitType type);
	////////////////////////////////////////////////////////////////
	Unit* pickAlienunit(Unit::UnitType type, bool fromBack = false);
	void  ReturnAlienUnit(Unit* r);
	double GetInfectionProb();
	void AddInfectedCountTotal();
	double GetInfectedRatio();
	///////////////////////////////////////////
	Unit* PickEarthUnit(Unit::UnitType type);
	void  ReturnEarthUnit(Unit* r);
	//////////////////////////////////
	Unit* PickAllyUnit();
	void  ReturnAllyUnit(Unit* r);
	/////////////////////////////////
	Unit* GetFromUML();
	void AddToUML(Unit* unit);
	void CheckingUML();
	void ReturnToUML(Unit* unit);
	void IncrementHealedUnitCount();
	int GetHealedUnitCount()const;
	bool canAddUnit(char army);
	///////////////////////////////////
	void PrintKilledList();
	void PrintUML();
	void loadFile(int& N, int& Prob,EarthArmyConfig* eParams, AlienArmyConfig* aParams, AllyArmyConfig* allyParams);
	~Game();
};