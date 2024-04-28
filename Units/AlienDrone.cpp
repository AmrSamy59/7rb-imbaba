#include "AlienDrone.h"
#include"../Game.h"
AlienDrone::AlienDrone(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::AD, gPtr, id, Tj, health, power, AC)
{

}
bool AlienDrone::Attack()
{
	//float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(EG->GetHealth());
	//EG->TakeDamage(Damage);
	return true;
}


