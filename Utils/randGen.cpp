#include "randGen.h"
//
//randGen::randGen(string input_file, EarthArmy* eArmy, AlienArmy* aArmy)
//{
//	earthArmy = eArmy;
//	alienArmy = aArmy;
//}

randGen::randGen(Game* GamePtr)
{
	srand((unsigned)time(NULL));
	EgC = 0;
	EsC = 0;
	EtC = 0;
	pGame = GamePtr;
	readParams();
}

void randGen::generateUnits(int es, int et, int eg, int as, int am, int ad)
{
	pGame->addEarthUnits(es, et, eg);
	pGame->addAlienUnits(as, am, ad);
}

void randGen::execute()
{
	int A = randInt(1, 100);
	if (A > Prob) return;
	int B;
	for (int i = 0; i < N; i++) {
		B = randInt(1, 100);
		if (B <= ES) ++EsC; //generate solider
		else if (B <= ES + ET) ++EtC; // generate tank
		else ++EgC; //generate Gunnery
	}
	for (int i = 0; i < N; i++) {
		B = randInt(1, 100);
		if (B <= AS) ++AsC; //generate solider
		else if (B <= AS + AM) ++AmC; // generate tank
		else ++AdC; //generate Gunnery
	}
	generateUnits(EsC, EtC, EgC, AsC, AmC, AdC);
	EsC = 0;
	EtC = 0;
	EgC = 0;
	AsC = 0;
	AmC = 0;
	AdC = 0;
}

void randGen::readParams()
{
	pGame->loadFile(N, Prob, ES, ET, EG, AS, AD, AM,
		ePowCeil, ePowFloor, eHealCeil, eHealFloor, eCapCeil, eCapFloor,
		aPowCeil, aPowFloor, aHealCeil, aHealFloor, aCapCeil, aCapFloor);
}

int randGen::randInt(int ceil, int floor)
{
	return ceil + (std::rand() % (floor - ceil +1));
}


