#include "EarthSoldier.h"

string EarthSoldier::UnitType()
{
	return "EarthSoldier";
}

EarthSoldier::EarthSoldier():Unit()
{


}

void EarthSoldier::Attack(Unit*AS)
{
	
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AS->GetHealth());
	AS->TakeDamage(Damage);

}

