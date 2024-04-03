#include "AlienDrone.h"
int AlienDrone::countAD = 0;
AlienDrone::AlienDrone()
{
	countAD++;
}
void AlienDrone::Attack(Unit*EG)
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(EG->GetHealth());
	EG->TakeDamage(Damage);

}

int AlienDrone::GetCount() const
{
	return countAD;
}

AlienDrone::~AlienDrone()
{
	--countAD;
}


