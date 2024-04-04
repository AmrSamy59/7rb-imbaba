#include "randGen.h"
//
//randGen::randGen(string input_file, EarthArmy* eArmy, AlienArmy* aArmy)
//{
//	earthArmy = eArmy;
//	alienArmy = aArmy;
//}

randGen::randGen(Game* GamePtr)
{
	EgC = 0;
	EsC = 0;
	EtC = 0;
	pGame = GamePtr;
}

void randGen::generateUnits(int s, int g, int t)
{
	pGame->addEarthUnits(s, g, t);
}

void randGen::execute(int N,int Prob,int ES, int ET, int EG)
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
	generateUnits(EsC, EtC, EgC);
}

int randGen::randInt(int ceil, int floor)
{
	return ceil + (std::rand() % (floor - ceil +1));
}


