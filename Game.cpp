#include "Game.h"

Game::Game(char _mode)
{
	earthArmy = new EarthArmy();
	alienArmy = new AlienArmy();
	randGenerator = new randGen(this);//replace this params with this pointer
	mode = _mode;
	timeStep = 0;
}

void Game::NextTimeStep()
{
	timeStep++;
	//handling files
	// then execute rand gen
	randGenerator->execute(7,100,30,30,40);//this is sample, delete it after files
	//earthArmy->Print(); // for the test anas magdy
	//earthArmy->Attack();
	//alienArmy->Attack();
}

void Game::addEarthUnits(int ES, int EG, int ET)
{
	cout << ES << "\t" << EG << "\t" << ET << endl;
	for (int i = 0; i < ES; i++) {
		EarthSoldier* soldier_ptr = new EarthSoldier();
		earthArmy->AddES(soldier_ptr);
		//soldier_ptr->PrintInfo();
	}
	for (int i = 0; i < ET; i++) {
		EarthTank* tank_ptr = new EarthTank();
		earthArmy->AddET(tank_ptr);
		tank_ptr->PrintInfo();
	}
	for (int i = 0; i < EG; i++) {
		EarthGunnery* gunnery_ptr = new EarthGunnery();
		earthArmy->AddEG(gunnery_ptr);
		gunnery_ptr->PrintInfo();
	}
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
	delete earthArmy;
	delete alienArmy;
	delete randGenerator;
	// clear from amr hany 







}


