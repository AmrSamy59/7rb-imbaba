#include "EarthTank.h"

#include"../Game.h"
EarthTank::EarthTank(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::ET, gPtr, id, Tj, health, power, AC)
{
}

bool EarthTank::Attack()
{
	/*float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AM->GetHealth());
	AM->TakeDamage(Damage);*/
	return true;
}

