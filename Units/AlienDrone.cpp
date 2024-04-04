#include "AlienDrone.h"

AlienDrone::AlienDrone()
{
	
}
void AlienDrone::Attack(Unit*EG)
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(EG->GetHealth());
	EG->TakeDamage(Damage);
}
string AlienDrone::UnitType()
{
	return "AlienDrone";
}


