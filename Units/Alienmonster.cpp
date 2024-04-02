#include "Alienmonster.h"
int Alienmonster::countAM = 0;
Alienmonster::Alienmonster() :Unit()
{
	countAM++;
}

void Alienmonster::Attack(Unit* EM)
{
	// nothing till now please wait
}

int Alienmonster::getcount() const
{
	return countAM;
}

Alienmonster::~Alienmonster()
{
	--countAM;
}

