#include "EarthTank.h"

EarthTank::EarthTank(Game* gPtr, int id, int Tj, float health, float power, int AC) :Unit(gPtr, id, Tj, health, power, AC)
{
	
}

void EarthTank::Attack(Unit*AM)
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AM->GetHealth());
	AM->TakeDamage(Damage);

}

string EarthTank::UnitType()
{
	return "EarthTank";
}


