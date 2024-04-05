#include "randGen.h"

randGen::randGen(Game* GamePtr)
{
	srand((unsigned)time(NULL));
	pGame = GamePtr;
	eParams = new EarthArmyParams();
	aParams = new AlienArmyParams();
	readParams();
}

//steps of generation
	//detect ID
	//randomize health for unit
	//randomize power for unit
	//then You can add this unit

void randGen::generateES() 
{
	int pow = randInt(eParams->ePowCeil,eParams->ePowFloor),
		health = randInt(eParams->eHealCeil,eParams->eHealFloor),
		cap = randInt(eParams->eCapCeil, eParams->eCapFloor);
		pGame->addEs_Unit(pow, health, cap);
}

void randGen::generateET()
{
	int pow = randInt(eParams->ePowCeil, eParams->ePowFloor),
		health = randInt(eParams->eHealCeil, eParams->eHealFloor),
		cap = randInt(eParams->eCapCeil, eParams->eCapFloor);

		pGame->addEt_Unit(pow, health, cap);
}

void randGen::generateEG()
{
	int pow = randInt(eParams->ePowCeil, eParams->ePowFloor),
		health = randInt(eParams->eHealCeil, eParams->eHealFloor),
		cap = randInt(eParams->eCapCeil, eParams->eCapFloor);

		pGame->addEg_Unit(pow, health, cap);

}

void randGen::generateAS()
{
	int pow = randInt(aParams->aPowCeil, aParams->aPowFloor),
		health = randInt(aParams->aHealCeil, aParams->aHealFloor),
		cap = randInt(aParams->aCapCeil, aParams->aCapFloor);

		pGame->addAs_Unit(pow, health, cap);
}

void randGen::generateAD()
{
	int pow = randInt(aParams->aPowCeil, aParams->aPowFloor),
		health = randInt(aParams->aHealCeil, aParams->aHealFloor),
		cap = randInt(aParams->aCapCeil, aParams->aCapFloor);

		pGame->addAd_Unit(pow, health, cap);

}

void randGen::generateAM()
{
	int pow = randInt(aParams->aPowCeil, aParams->aPowFloor),
		health = randInt(aParams->aHealCeil, aParams->aHealFloor),
		cap = randInt(aParams->aCapCeil, aParams->aCapFloor);

		pGame->addAm_Unit(pow, health, cap);

}

void randGen::execute()
{
	int A = randInt(1, 100);
	if (A > Prob) return;
	int B;
	for (int i = 0; i < N; i++) {
		B = randInt(1, 100);
		if (B <= eParams->ES) generateES(); 
		else if (B <= eParams->ES + eParams->ET) generateET();
		else generateEG();
	}
	for (int i = 0; i < N; i++) {
		B = randInt(1, 100);
		if (B <= aParams->AS) generateAS();
		else if (B <= aParams->AS + aParams->AM) generateAM();
		else generateAD();
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


