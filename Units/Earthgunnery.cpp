#include "EarthGunnery.h"

string EarthGunnery::UnitType()
{
	return "EarthGunnery";
}

EarthGunnery::EarthGunnery(Game* gPtr, int id, int Tj, float health, float power, int AC) :Unit(gPtr, id, Tj, health, power, AC)
{

}

void EarthGunnery::Attack(Unit* AD)
{

	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AD->GetHealth());	
	AD->TakeDamage(Damage);

}

