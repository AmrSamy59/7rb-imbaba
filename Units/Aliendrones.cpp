#include "Aliendrones.h"
int Aliendrones::countAD = 0;
Aliendrones::Aliendrones()
{
	countAD++;
}
void Aliendrones::Attack(Unit*EG)
{
	// nothing till now please wait
	float Damage = ((this->Getpower()) * (this->Gethealth() / 100)) / sqrt(EG->Gethealth());
	// nothing till now please wait
	EG->Health_decrease(Damage);

}

int Aliendrones::getcount() const
{
	return countAD;
}

Aliendrones::~Aliendrones()
{
	--countAD;
}


