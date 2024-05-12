#include "Game.h"

Game::Game(char _mode)
{
	earthArmy = new EarthArmy();
	alienArmy = new AlienArmy();
	allyArmy = new AllyArmy();
	randGenerator = new randGen(this);
	mode = _mode;
	game_status = 0;
	timeStep = 0;

	for (int i = 0; i < Unit::LastType; ++i) {
		DestructedUnitsCount[i] = 0;
	}
}

void Game::PlayGame(char game_mode)
{
	while (GetCurrentTimeStep() < 40 || checkGameStatus() == 0) {
		NextTimeStep();
		if (game_mode == 'i') {
			cout << "Press Enter to continue..." << endl;
			string s;
			getline(cin, s);
		}
	}

	int game_status = checkGameStatus();

	if (game_status == -1) {
		// Kill all units in UML
		while (!UML.isEmpty()) {
			Unit* unit = nullptr;
			int p;
			UML.dequeue(unit, p);
			AddToKilledList(unit);
		}
			
	}
	else if (game_status == 1 || game_status == 2) {
	// Return all units in UML to earth army
		while (!UML.isEmpty()) {
			Unit* unit = nullptr;
			int p;
			UML.dequeue(unit, p);
			earthArmy->AddUnit(unit);
		}
	}

	LogGameResult();
	//In Silent Don't print this
	if (game_status == 1) {
		cout << endl << "Earth Army Won" << endl;
	}
	else if (game_status == -1) {
		cout << endl << "Aliens Army Won" << endl;
	}
	else if (game_status == 2) {
		cout << endl << "TIE" << endl;
	}

	if (game_mode == 's')
		cout << "Simulation ends, Output file is created" << endl;

}

void Game::LogGameResult()
{
	logger->LogEarthArmy(earthArmy);
	logger->LogAlienArmy(alienArmy);
	logger->LogGameStatus();
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

	bool retreated = false;
	if (earthArmy->GetInfectedCount() == 0) {
		retreated = allyArmy->ArmyRetreat();
	}
	randGenerator->execute();
	// Printing
	if (mode == 'i') {
		cout << "\nCurrent Timestep " << timeStep << endl;
		if (retreated) {
			cout << endl << "Ally Army retreated" << endl << endl;
		}
		// Printing alive lists
		earthArmy->Print();
		alienArmy->Print();
		allyArmy->Print();

		cout << "============================== Units Fighting At Current Step =====================" << endl;
	}


	// Printing ongoing fights
	earthArmy->Attack();
	earthArmy->SpreadInfection();
	allyArmy->Attack();
	alienArmy->Attack();
	
	// Printing dead units
	if (mode == 'i')
	{
		cout << endl;
		PrintUML();
		PrintKilledList();
	}
}

int Game::GetCurrentTimeStep() const
{
	return timeStep;
}


int Game::getNextUnitId(char army)
{
	if (army == 'a')
		return alienArmy->getNextUnitId();
	else if(army=='s')
	{
		return allyArmy->getNextUnitId();
	}
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

bool Game::CanEtAttackAs()
{
	double currentRatio = GetRatio();
	if (ETapproval) {
		if (currentRatio >= 80.0) ETapproval = false;
	}
	else {
		if (currentRatio < 30.0) ETapproval = true;
	}
	return ETapproval;
}

double Game::GetRatio()
{
	if(alienArmy->GetUnitCount(Unit::AS) != 0.0)
		return (double(earthArmy->GetUnitCount(Unit::ES)) / double(alienArmy->GetUnitCount(Unit::AS))) * 100.0;
	return 100.0;
}

void Game::addUnit(Unit* unit)
{
	if (!unit) return;
	if(unit->getType() == Unit::EG || unit->getType() == Unit::ES || unit->getType() == Unit::ET|| unit->getType() == Unit::HU)
		earthArmy->AddUnit(unit);
	else if (unit->getType() == Unit::SU) {

		allyArmy->AddUnit(unit);
	}
	else alienArmy->AddUnit(unit);

}



void Game::AddToKilledList(Unit* unit)
{
	DestructedUnitsCount[unit->getType()]++;
	if(unit->getType() == Unit::HU)
		unit->TakeDamage(unit->GetHealth()); // to actually kill the healer
	unit->SetDestructionTime(timeStep);
	Killed.enqueue(unit);
	logger->LogUnit(unit);
}

int Game::GetDestructedUnitCount(Unit::UnitType type)
{
	return DestructedUnitsCount[type];
}

Unit* Game::pickAlienunit(Unit::UnitType type,bool fromBack)
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
	case(Unit::AD):
	{
		return alienArmy->RemoveUnit(Unit::AD, fromBack);
		break;
	}
	}

	return nullptr;
}

void Game::ReturnAlienUnit(Unit* r)
{
	alienArmy->AddUnit(r);

}

double Game::GetInfectionProb()
{
	return alienArmy->GetInfectionProb();
}

void Game::AddInfectedCountTotal()
{
	earthArmy->AddInfectedCountTotal();
}

double Game::GetInfectedRatio()
{
	int escount = earthArmy->GetUnitCount(Unit::ES);
	int infectedcount = earthArmy->GetInfectedCount();
	if (escount == 0)
		return 0.0;
	else
	{
		double ratio = double(infectedcount) / double(escount);
		return ratio*100.0;
	}

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

Unit* Game::PickAllyUnit()
{
	Unit *unit =nullptr;
	unit=allyArmy->RemoveUnit();
	return unit;
}

void Game::ReturnAllyUnit(Unit* r)
{
	allyArmy->AddUnit(r);
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
void Game::IncrementHealedUnitCount()
{
	++HealedUnitCount;
}
int Game::GetHealedUnitCount() const
{
	return HealedUnitCount;
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

void Game::loadFile(int& N, int& Prob, EarthArmyConfig* eParams, AlienArmyConfig* aParams, AllyArmyConfig* allyParams)
{
	cout << "Please, Enter the Name of the input file: ";
	cin >> file;
	// check if the file name has .txt extension
	if (file.find(".txt") == string::npos) {
		file += ".txt";
	}
	file = "Input/" + file;
	cin.ignore();
	ifstream inFile(file);
	while (!inFile.is_open()) {
		cout << "Couldn't Find it\nPlease Enter Your File name Correctly: ";
		cin >> file;
		if (file.find(".txt") == string::npos) {
			file += ".txt";
		}
		file = "Input/" + file;
		cin.ignore();
		inFile.open(file);
	}
	double infectionProb;
		inFile >> N
			>> eParams->ES >> eParams->ET >> eParams->EG >> eParams->HU
			>> aParams->AS >> aParams->AM >> aParams->AD
			>> Prob >> allyParams->threshold >> infectionProb
			>> eParams->ePowCeil >> eParams->ePowFloor 
			>> eParams->eHealCeil >> eParams->eHealFloor 
			>> eParams->eCapCeil >> eParams->eCapFloor
			>> aParams->aPowCeil >> aParams->aPowFloor 
			>> aParams->aHealCeil >> aParams->aHealFloor 
			>> aParams->aCapCeil >> aParams->aCapFloor
			>>allyParams->allyPowCeil >> allyParams->allyPowFloor
			>> allyParams->allyHealCeil >> allyParams->allyHealFloor
			>> allyParams->allyCapCeil >> allyParams->allyCapFloor;
		eParams->ePowFloor *= -1;
		eParams->eHealFloor *= -1;
		eParams->eCapFloor *= -1;
		aParams->aPowFloor *= -1;
		aParams->aHealFloor *= -1;
		aParams->aCapFloor *= -1;
		allyParams->allyPowFloor *= -1;
		allyParams->allyHealFloor *= -1;
		allyParams->allyCapFloor *= -1;
	inFile.close();

	alienArmy->SetInfectionProb(infectionProb);
	string output_file;
	cout << "Enter Output File Name: ";
	cin >> output_file;

	// check if the file name has .txt extension
	if (output_file.find(".txt") == string::npos) {
		output_file += ".txt";
	}
	cin.ignore();
	logger = new OutputLogger("Output/" + output_file, this);
}

Game::~Game()
{
	delete earthArmy;
	delete alienArmy;
	delete randGenerator;
	delete logger;
}


