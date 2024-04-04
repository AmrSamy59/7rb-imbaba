#include "EarthGunnery.h"

string EarthGunnery::UnitType()
{
	return "EarthGunnery";
}

EarthGunnery::EarthGunnery() :Unit()
{

}

void EarthGunnery::Attack(Unit* AD)
{

	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AD->GetHealth());	
	AD->TakeDamage(Damage);

}

