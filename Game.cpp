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

void Game::addEarthUnits(int ES, int ET, int EG)
{
	for (int i = 0; i < ES; i++) {
		EarthSoldier* soldier_ptr = new EarthSoldier();
		earthArmy->AddES(soldier_ptr);
		//soldier_ptr->PrintInfo();
	}
	for (int i = 0; i < ET; i++) {
		EarthTank* tank_ptr = new EarthTank();
		earthArmy->AddET(tank_ptr);
		//tank_ptr->PrintInfo();
	}
	for (int i = 0; i < EG; i++) {
		EarthGunnery* gunnery_ptr = new EarthGunnery();
		earthArmy->AddEG(gunnery_ptr);
		//gunnery_ptr->PrintInfo();
	}
}

void Game::addAlienUnits(int AS, int AM, int AD)
{
	for (int i = 0; i < AS; i++) {
		AlienSoldier* soldier_ptr = new AlienSoldier();
		alienArmy->AddAS(soldier_ptr);
		//soldier_ptr->PrintInfo();
	}
	for (int i = 0; i < AM; i++) {
		AlienMonster* monster_ptr = new AlienMonster();
		alienArmy->AddAM(monster_ptr);
		//tank_ptr->PrintInfo();
	}
	for (int i = 0; i < AD; i++) {
		AlienDrone* drone_ptr = new AlienDrone();
		alienArmy->AddAD(drone_ptr);
		//gunnery_ptr->PrintInfo();
	}
}

//REPLACE THIS PARAMS WITH NEW OBJECT OF NEW CLASS THAT GROUP ALL THIS PARAMS 
// AND WRITE A FUNCTION THAT MANAGE ALL OF THIS 
// DO NOT FORGET!!!!!!!!!!!!!!!

void Game::loadFile(int& N,int& Prob, int& ES, int& EG, int& ET, int& AS, int& AD, int& AM,
	int& ePowRangeCeil,
	int& ePowRangeFloor,
	int& eHealRangeCeil,
	int& eHealRangeFloor,
	int& eAttackCapCeil,
	int& eAttackCapFloor,
	int& aPowRangeCeil,
	int& aPowRangeFloor,
	int& aHealRangeCeil,
	int& aHealRangeFloor,
	int& aAttackCapCeil,
	int& aAttackCapFloor
	)
{
	ifstream inFile(file);
	if (inFile.is_open()) {
		inFile >> N >> Prob
			>> ES >> EG >> ET
			>> AS >> AD >> AM
			>> ePowRangeCeil >> ePowRangeFloor >> eHealRangeCeil >> eHealRangeFloor >> eAttackCapCeil >> eAttackCapFloor
			>> aPowRangeCeil >> aPowRangeFloor >> aHealRangeCeil >> aHealRangeFloor >> aAttackCapCeil >> aAttackCapFloor;
		ePowRangeFloor *= -1;
		eHealRangeFloor *= -1;
		eAttackCapFloor *= -1;
		aPowRangeFloor *= -1;
		aHealRangeFloor *= -1;
		aAttackCapFloor *= -1;
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
	Temp.~LinkedQueue();
	Killed.~LinkedQueue();
	//delete earthArmy;
	//delete alienArmy;
	delete randGenerator;
	cout << "delete done";
	// clear from amr hany 







}


