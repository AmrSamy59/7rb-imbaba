#include "Earthsoldier.h"
int Earthsoldier::countES = 0;
Earthsoldier::Earthsoldier():Unit()
{
	++countES;

}

void Earthsoldier::Attack(Unit*AS)
{
	// nothing till now please wait 
	
}

int Earthsoldier::getcount()
{
	return countES;
}

Earthsoldier::~Earthsoldier()
{
	--countES;
}

