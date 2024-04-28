#include "Game.h"

Game::Game(char _mode)
{
	earthArmy = new EarthArmy();
	alienArmy = new AlienArmy();
	randGenerator = new randGen(this);
	mode = _mode;
	game_status = 0;
	timeStep = 0;
}



char Game::GetGameMode()
{
	return mode;
}

int Game::checkGameStatus()
{
	int e_count = earthArmy->GetArmyCount();
	int a_count = alienArmy->GetArmyCount();

	if (e_count == 0 && a_count != 0)
		game_status = -1; // aliens won
	else if (a_count == 0 && e_count != 0)
		game_status = 1; // earth won
	else if ((e_count == 0 && a_count == 0) || !canArmiesAttack()) {
		game_status = 2; // tie
	}

	return game_status;
}

void Game::NextTimeStep()
{
	timeStep++;

	if(timeStep >= 10)
		CheckingUML();

	randGenerator->execute();
	// Printing
	if (mode == 'i') {
		cout << "\nCurrent Timestep " << timeStep << endl;
		// Printing alive lists
		earthArmy->Print();
		alienArmy->Print();

		cout << "============================== Units Fighting At Current Step ======================" << endl;
	}


	// Printing ongoing fights
	earthArmy->Attack();
	alienArmy->Attack();

	// Printing dead units
	if (mode == 'i')
	{
		cout << endl;
		PrintUML();
		PrintKilledList();
	}

}

void Game::NextTimeStepTest()
{ 
	// for phase 1.2 only

	timeStep++;
	
	randGenerator->execute();

	int x = rand() % 100 + 1;
	Unit* unit = nullptr;
	cout << endl << "X = " << x << endl;
	if (x < 10) {
		unit = earthArmy->RemoveUnit(Unit::ES);
		if(unit)
			earthArmy->AddUnit(unit);
	}
	else if (x < 20) {
		unit = earthArmy->RemoveUnit(Unit::ET);
		if (unit)
			AddToKilledList(unit);
	}
	else if (x < 30) {
		unit = earthArmy->RemoveUnit(Unit::EG);
		if (unit) {
			unit->TakeDamage(unit->GetHealth() / 2);
			earthArmy->AddUnit(unit);
		}
	}
	else if (x < 40) {
		LinkedQueue<Unit*> Temp;
		for (int i = 0; i < 5; ++i) {
			unit = alienArmy->RemoveUnit(Unit::AS);
			if (unit) {
				unit->TakeDamage(unit->GetHealth() / 2);
				Temp.enqueue(unit);
			}
		}
		while (!Temp.isEmpty()) {
			Temp.dequeue(unit);
			alienArmy->AddUnit(unit);
		}

	}
	else if (x < 50) {
		for (int i = 0; i < 5; ++i) {
			unit = alienArmy->RemoveUnit(Unit::AM);
			if (unit) {
				alienArmy->AddUnit(unit);
			}
		}
	}
	else if (x < 60) {
		for (int i = 0; i < 3; ++i) {
			unit = alienArmy->RemoveUnit(Unit::AD);
			if (unit) {
				AddToKilledList(unit);
			}

			unit = alienArmy->RemoveUnit(Unit::AD, true);
			if (unit) {
				AddToKilledList(unit);
			}
		}
	}
	earthArmy->Print(); 
	alienArmy->Print();
	PrintKilledList();
}

int Game::GetCurrentTimeStep() const
{
	return timeStep;
}


int Game::getNextUnitId(char army)
{
	if (army == 'a')
		return alienArmy->getNextUnitId();
	return earthArmy->getNextUnitId();
}

int Game::getTj()
{
	return timeStep;
}

Game* Game::GetGamePtr()
{
	
	return this;
}

bool Game::canArmiesAttack()
{

	if (earthArmy->GetUnitCount(Unit::ES) > 0
		&& alienArmy->GetUnitCount(Unit::AS) > 0) { // ES attacks AS (& vv)
		return true;
	}
	if (earthArmy->GetUnitCount(Unit::ET) > 0
		&& (alienArmy->GetUnitCount(Unit::AM) > 0
			|| alienArmy->GetUnitCount(Unit::AS) > 0)) { // ET attacks AM & AS
		return true;
	}
	if (earthArmy->GetUnitCount(Unit::EG) > 0
		&& (alienArmy->GetUnitCount(Unit::AM) > 0
			|| alienArmy->GetUnitCount(Unit::AD) > 0)) { // EG attacks AM & AD
		return true;
	}
	if (alienArmy->GetUnitCount(Unit::AM) > 0
		&& (earthArmy->GetUnitCount(Unit::ET) > 0
			|| earthArmy->GetUnitCount(Unit::ES) > 0)) { // AM attacks ET & ES
		return true;
	}
	if (alienArmy->GetUnitCount(Unit::AD) > 0
		&& (earthArmy->GetUnitCount(Unit::ET) > 0
			|| earthArmy->GetUnitCount(Unit::EG) > 0)) { // AD attacks ET & EG
		return true;
	}
	// otherwise, none can hit the other
	return false;
}

void Game::addUnit(Unit* unit)
{
	if (!unit) return;
	if(unit->getType() == Unit::EG || unit->getType() == Unit::ES || unit->getType() == Unit::ET|| unit->getType() == Unit::HU)
		earthArmy->AddUnit(unit);
	alienArmy->AddUnit(unit);
}



void Game::AddToKilledList(Unit* unit)
{
	Killed.enqueue(unit);
}

Unit* Game::pickAlienunit(Unit::UnitType type)
{

	switch (type)
	{
	case(Unit::AS):
	{
		return alienArmy->RemoveUnit(Unit::AS);
		break;

	}case(Unit::AM):
	{
		return alienArmy->RemoveUnit(Unit::AM);
		break;
	}
	///////////// complete the drones i don't know what you need (Amr hany)

	}

	return nullptr;
}

void Game::ReturnAlienUnit(Unit* r)
{
	alienArmy->AddUnit(r);

}

Unit* Game::PickEarthUnit(Unit::UnitType type)
{
	switch (type)
	{
	case (Unit::EG):
	{
		return earthArmy->RemoveUnit(Unit::EG);
		break;

	}
	case (Unit::ES):
	{
		return earthArmy->RemoveUnit(Unit::ES);
		break;
	}
	case (Unit::ET):
	{
		return earthArmy->RemoveUnit(Unit::ET);
		break;
	}

	}



	return nullptr;
}

void Game::ReturnEarthUnit(Unit* r)
{
	earthArmy->AddUnit(r);

}


Unit* Game::GetFromUML()
{
	Unit* p = nullptr;
	int x;
	if (UML.dequeue(p, x))
		return p;
	else
		return nullptr;
}

void Game::ReturnToUML(Unit* unit)
{
	//// use for tanks and earth solider only //////////
	if (!unit) return;
	float pri = 0;
	if (unit->getType() == Unit::ES) {
		pri = 100 - unit->GetHealth();
		UML.enqueue(unit, pri);
	}
	if (unit->getType() == Unit::ET) {
		UML.enqueue(unit, pri);
	}
}
void Game::AddToUML(Unit* unit)
{
	//// use for tanks and earth solider only //////////
	if (!unit) return;
	float pri = 0;
	if (unit->getType()==Unit::ES) {
		pri = 100 - unit->GetHealth();
		unit->SetHealtime(this->GetCurrentTimeStep());
		UML.enqueue(unit, pri);
	}
	if (unit->getType() == Unit::ET) {
		unit->SetHealtime(this->GetCurrentTimeStep());
		UML.enqueue(unit, pri);
	}
}

void Game::CheckingUML()
{
	/// checking for the 10 time step ////////////////
	/// used when you next time step /////////////////
	if (UML.isEmpty()) return;
	priQueue<Unit*>tempcheck;
	
	while (!UML.isEmpty())
	{
		int p;
		Unit* ptr;
		UML.dequeue(ptr, p);
		if (abs(ptr->GetHealtime() - this->GetCurrentTimeStep()) >= 10) {
			AddToKilledList(ptr);
		}
		else {
			tempcheck.enqueue(ptr, p);
		}
	}

	while (!tempcheck.isEmpty())
	{
		int p;
		Unit* ptr;
		tempcheck.dequeue(ptr, p);
		UML.enqueue(ptr, p);
	}
}


void Game::PrintKilledList() {
	cout << "============================== Killed/Destructed Units =============================" << endl;
	cout << Killed.GetCount() << " units [";
	Killed.Print();
	cout << "] " << endl << endl;
}

void Game::PrintUML() {
	cout << "============================== Unit Maintenance List (UML) =========================" << endl;
	cout << UML.GetCount() << " units [";
	UML.Print();
	cout << "] " << endl << endl;
}

void Game::loadFile(int& N, int& Prob, EarthArmyConfig* eParams, AlienArmyConfig* aParams)
{
	cout << "Please, Enter the Name of the file: ";
	cin >> file;
	file += ".txt";
	cin.ignore();
	ifstream inFile(file);
	while (!inFile.is_open()) {
		cout << "Couldn't Find it\nPlease Enter Your File name Correctly and Without .txt: ";
		cin >> file;
		file += ".txt";
		cin.ignore();
		inFile.open(file);
	}
		inFile >> N
			>> eParams->ES >> eParams->EG >> eParams->ET >> eParams->HU
			>> aParams->AS >> aParams->AD >> aParams->AM
			>> Prob
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
	inFile.close();
}

Game::~Game()
{
	delete earthArmy;
	delete alienArmy;
	delete randGenerator;
}


