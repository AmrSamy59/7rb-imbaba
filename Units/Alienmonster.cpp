#include "Alienmonster.h"
int Alienmonster::countAM = 0;
Alienmonster::Alienmonster() :Unit()
{
	countAM++;
}

void Alienmonster::Attack(Unit* EM)
{
	// nothing till now please wait
	float Damage = ((this->Getpower()) * (this->Gethealth() / 100)) / sqrt(EM->Gethealth());
	// nothing till now please wait
	EM->Health_decrease(Damage);

}

int Alienmonster::getcount() const
{
	return countAM;
}

Alienmonster::~Alienmonster()
{
	--countAM;
}

