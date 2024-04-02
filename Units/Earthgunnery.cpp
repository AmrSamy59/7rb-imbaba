#include "Earthgunnery.h"
int Earthgunnery::countEG = 0;
Earthgunnery::Earthgunnery() :Unit()
{
	countEG++;
}

void Earthgunnery::Attack(Unit* AD)
{
	// nothing till now please wait 
	//AD.Sethealth(AD.Gethealth() - this->Getpower());
}

int Earthgunnery::getcount()
{
	return countEG ;
}

Earthgunnery::~Earthgunnery()
{
	--countEG;
}

