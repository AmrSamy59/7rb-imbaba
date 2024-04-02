#include "Aliendrones.h"
int Aliendrones::countAD = 0;
Aliendrones::Aliendrones()
{
	countAD++;
}
void Aliendrones::Attack(Unit*EG)
{
	// nothing till now please wait
}

int Aliendrones::getcount() const
{
	return countAD;
}

Aliendrones::~Aliendrones()
{
	--countAD;
}


