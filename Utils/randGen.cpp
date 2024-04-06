#include "randGen.h"

randGen::randGen(Game* GamePtr)
{
	srand((unsigned)time(NULL));
	pGame = GamePtr;
	eParams = new EarthArmyConfig();
	aParams = new AlienArmyConfig();
	readParams();
}

//steps of generation
	//detect ID
	//randomize health for unit
	//randomize power for unit
	//then You can add this unit


void randGen::generateUnit(Unit::UnitType UnitType)
{
	int Id, Tj, pow, health, Cap;
	Unit* unit = nullptr;
	if (UnitType == Unit::EG || UnitType == Unit::ES || UnitType == Unit::ET)
	{
		pow = randInt(eParams->ePowCeil, eParams->ePowFloor),
			health = randInt(eParams->eHealCeil, eParams->eHealFloor),
			Cap = randInt(eParams->eCapCeil, eParams->eCapFloor),
			Id = pGame->getNextUnitId('e');
	}
	else {
		pow = randInt(aParams->aPowCeil, aParams->aPowFloor),
			health = randInt(aParams->aHealCeil, aParams->aHealFloor),
			Cap = randInt(aParams->aCapCeil, aParams->aCapFloor),
			Id = pGame->getNextUnitId('a');
	}
	
	Tj = pGame->getTj();
	switch (UnitType)
	{
		case Unit::AD:
		{
			unit = new AlienDrone(pGame, Id, Tj, health, pow, Cap);
			break;
		}
		case Unit::AM:
		{
			unit = new AlienMonster(pGame, Id, Tj, health, pow, Cap);
			break;
		}
		case Unit::AS:
		{
			unit = new AlienSoldier(pGame, Id, Tj, health, pow, Cap);
			break;
		}
		case Unit::EG:
		{
			unit = new EarthGunnery(pGame, Id, Tj, health, pow, Cap);
			break;
		}
		case Unit::ES:
		{
			unit = new EarthSoldier(pGame, Id, Tj, health, pow, Cap);
			break;
		}
		case Unit::ET:
		{
			unit = new EarthTank(pGame, Id, Tj, health, pow, Cap);
			break;
		}
	}
	pGame->addUnit(unit);
}



void randGen::execute()
{
	int A = randInt(1, 100);
	if (A > Prob) return;
	int B;
	for (int i = 0; i < N; i++) {
		B = randInt(1, 100);
		if (B <= eParams->ES) generateUnit(Unit::ES); 
		else if (B <= eParams->ES + eParams->ET) generateUnit(Unit::ET);
		else generateUnit(Unit::EG);
	}
	for (int i = 0; i < N; i++) {
		B = randInt(1, 100);
		if (B <= aParams->AS) generateUnit(Unit::AS);
		else if (B <= aParams->AS + aParams->AM) generateUnit(Unit::AM);
		else generateUnit(Unit::AD);
	}
}

void randGen::readParams()
{
	pGame->loadFile(N, Prob, eParams, aParams);
}

int randGen::randInt(int ceil, int floor)
{
	return ceil + (std::rand() % (floor - ceil +1));
}


