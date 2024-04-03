#include "Alienmonster.h"
int Alienmonster::countAM = 0;
Alienmonster::Alienmonster() :Unit()
{
	countAM++;
}

void Alienmonster::Attack(Unit* EM)
{
	float Damage = ((this->Getpower()) * (this->Gethealth() / 100)) / sqrt(EM->Gethealth());
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

