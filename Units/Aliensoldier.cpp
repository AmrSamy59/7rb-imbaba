#include "Aliensoldier.h"
int Aliensoldier::countAS = 0;
Aliensoldier::Aliensoldier() :Unit()
{
	countAS++;

}

void Aliensoldier::Attack(Unit*ES)
{
	float Damage = ((this->Getpower()) * (this->Gethealth() / 100)) / sqrt(ES->Gethealth());
	// nothing till now please wait
	ES->Health_decrease(Damage);
	

}


int Aliensoldier::getcount()
{
	return countAS;
}

Aliensoldier::~Aliensoldier()
{
	--countAS;
}
