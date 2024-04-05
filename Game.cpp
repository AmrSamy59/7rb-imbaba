#include "Game.h"

Game::Game(char _mode)
{
	//Anas Note: Don't Forget to read the name of the file
	file = "input_data.txt";
	earthArmy = new EarthArmy();
	alienArmy = new AlienArmy();
	randGenerator = new randGen(this);
	mode = _mode;
	timeStep = 0;
}

void Game::NextTimeStep()
{
	timeStep++;
	//handling files
	// then execute rand gen
	randGenerator->execute();//this is sample, delete it after files
	earthArmy->Print(); // for the test anas magdy
	alienArmy->Print();
	//earthArmy->Attack();
	//alienArmy->Attack();
}
/*
void Game::addEarthUnits(int ES, int ET, int EG)
{
	int id = earthArmy->getNextUnitId();
	for (int i = 0; i < ES; i++) {
		EarthSoldier* soldier_ptr = new EarthSoldier(this, id);
		earthArmy->AddES(soldier_ptr);
		//soldier_ptr->PrintInfo();
	}
	for (int i = 0; i < ET; i++) {
		EarthTank* tank_ptr = new EarthTank(this, id);
		earthArmy->AddET(tank_ptr);
		//tank_ptr->PrintInfo();
	}
	for (int i = 0; i < EG; i++) {
		EarthGunnery* gunnery_ptr = new EarthGunnery(this, id);
		earthArmy->AddEG(gunnery_ptr);
		//gunnery_ptr->PrintInfo();
	}
}

void Game::addAlienUnits(int AS, int AM, int AD)
{
	int id = alienArmy->getNextUnitId();
	for (int i = 0; i < AS; i++) {
		AlienSoldier* soldier_ptr = new AlienSoldier(this, id);
		alienArmy->AddAS(soldier_ptr);
		//soldier_ptr->PrintInfo();
	}
	for (int i = 0; i < AM; i++) {
		AlienMonster* monster_ptr = new AlienMonster(this, id);
		alienArmy->AddAM(monster_ptr);
		//tank_ptr->PrintInfo();
	}
	for (int i = 0; i < AD; i++) {
		AlienDrone* drone_ptr = new AlienDrone(this, id);
		alienArmy->AddAD(drone_ptr);
		//gunnery_ptr->PrintInfo();
	}
}
*/
void Game::addEs_Unit(int pow, int health, int Cap)
{
	int id = earthArmy->getNextUnitId();
	EarthSoldier* soldier_ptr = new EarthSoldier(this,id,timeStep,health,pow,Cap);
	earthArmy->AddES(soldier_ptr);
}

void Game::addEt_Unit(int pow, int health, int Cap)
{
	int id = earthArmy->getNextUnitId();
	EarthTank* tank_ptr = new EarthTank(this, id, timeStep, health, pow, Cap);
	earthArmy->AddET(tank_ptr);
}

void Game::addEg_Unit(int pow, int health, int Cap)
{
	int id = earthArmy->getNextUnitId();
	EarthGunnery* gunnery_ptr = new EarthGunnery(this, id, timeStep, health, pow, Cap);
	earthArmy->AddEG(gunnery_ptr);
}

void Game::addAs_Unit(int pow, int health, int Cap)
{
	int id = earthArmy->getNextUnitId();
	AlienSoldier* soldier_ptr = new AlienSoldier(this, id, timeStep, health, pow, Cap);
	alienArmy->AddAS(soldier_ptr);
}

void Game::addAd_Unit(int pow, int health, int Cap)
{
	int id = alienArmy->getNextUnitId();
	AlienDrone* drone_ptr = new AlienDrone(this, id, timeStep, health, pow, Cap);
	alienArmy->AddAD(drone_ptr);
}

void Game::addAm_Unit(int pow, int health, int Cap)
{
	int id = alienArmy->getNextUnitId();
	AlienMonster* monster_ptr = new AlienMonster(this, id, timeStep, health, pow, Cap);
	alienArmy->AddAM(monster_ptr);
}

//REPLACE THIS PARAMS WITH NEW OBJECT OF NEW CLASS THAT GROUP ALL THIS PARAMS 
// AND WRITE A FUNCTION THAT MANAGE ALL OF THIS 
// DO NOT FORGET!!!!!!!!!!!!!!!

void Game::loadFile(int& N, int& Prob, EarthArmyParams* eParams, AlienArmyParams* aParams)
{
	ifstream inFile(file);
	if (inFile.is_open()) {
		inFile >> N >> Prob
			>> eParams->ES >> eParams->EG >> eParams->ET
			>> aParams->AS >> aParams->AD >> aParams->AM
			>> eParams->ePowCeil >> eParams->ePowFloor 
			>> eParams->eHealCeil >> eParams->eHealFloor 
			>> eParams->eCapCeil >> eParams->eCapFloor
			>> aParams->aPowCeil >> aParams->aPowFloor 
			>> aParams->aHealCeil >> aParams->aHealFloor 
			>> aParams->aCapCeil >> aParams->aCapFloor;
		eParams->ePowFloor *= -1;
		eParams->eHealFloor *= -1;
		eParams->eCapFloor *= -1;
		aParams->aPowFloor *= -1;
		aParams->aHealFloor *= -1;
		aParams->aCapFloor *= -1;
	}
	inFile.close();
}

Game::~Game()
{
	//delete lists done
	//armies pointers done 
	// 	randgen done ;
	// clear from amr hany 
	earthArmy->~EarthArmy();
	alienArmy->~AlienArmy();
	Killed.~LinkedQueue();
	//delete earthArmy;
	//delete alienArmy;
	delete randGenerator;
	cout << "delete done";
	// clear from amr hany 







}


