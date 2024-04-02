#include "Earthtank.h"
int Earthtank::countET = 0;
Earthtank::Earthtank():Unit()
{
	++countET;
}

void Earthtank::Attack(Unit*AM)
{
	float Damage = ((this->Getpower()) * (this->Gethealth() / 100)) / sqrt(AM->Gethealth());
	// nothing till now please wait
	AM->Health_decrease(Damage);

}

int Earthtank::getcount()
{
	return countET;
}

Earthtank::~Earthtank()
{
	--countET;
}
