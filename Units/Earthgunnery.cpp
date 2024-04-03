#include "Earthgunnery.h"
int Earthgunnery::countEG = 0;
Earthgunnery::Earthgunnery() :Unit()
{
	countEG++;
}

void Earthgunnery::Attack(Unit* AD)
{

	float Damage = ((this->Getpower()) * (this->Gethealth() / 100)) / sqrt(AD->Gethealth());	
	AD->Health_decrease(Damage);

}

int Earthgunnery::getcount()
{
	return countEG ;
}

Earthgunnery::~Earthgunnery()
{
	--countEG;
}

