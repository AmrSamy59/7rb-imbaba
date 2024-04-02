#include "Earthsoldier.h"
int Earthsoldier::countES = 0;
Earthsoldier::Earthsoldier():Unit()
{
	++countES;

}

void Earthsoldier::Attack(Unit*AS)
{
	// nothing till now please wait 
	float Damage = ((this->Getpower()) * (this->Gethealth() / 100)) / sqrt(AS->Gethealth());
	// nothing till now please wait
	AS->Health_decrease(Damage);

}

int Earthsoldier::getcount()
{
	return countES;
}

Earthsoldier::~Earthsoldier()
{
	--countES;
}

