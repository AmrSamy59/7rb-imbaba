#include "EarthTank.h"

EarthTank::EarthTank():Unit()
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


