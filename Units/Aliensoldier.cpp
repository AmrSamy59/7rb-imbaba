#include "Aliensoldier.h"
int Aliensoldier::countAS = 0;
Aliensoldier::Aliensoldier() :Unit()
{
	countAS++;

}

void Aliensoldier::Attack(Unit*ES)
{
	// nothing till now please wait
	

}


int Aliensoldier::getcount()
{
	return countAS;
}

Aliensoldier::~Aliensoldier()
{
	--countAS;
}
