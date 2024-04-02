#include "Earthtank.h"
int Earthtank::countET = 0;
Earthtank::Earthtank():Unit()
{
	++countET;
}

void Earthtank::Attack(Unit*AM)
{
	// nothing till now please wait 
	//AM.Sethealth(AM.Gethealth() - this->Getpower());
}

int Earthtank::getcount()
{
	return countET;
}

Earthtank::~Earthtank()
{
	--countET;
}
