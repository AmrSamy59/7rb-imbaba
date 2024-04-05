#include "AlienDrone.h"

AlienDrone::AlienDrone(Game* gPtr, int id, int Tj, float health, float power, int AC) :Unit(gPtr, id, Tj, health, power, AC)
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


