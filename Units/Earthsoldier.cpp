#include "EarthSoldier.h"
int EarthSoldier::countES = 0;
EarthSoldier::EarthSoldier():Unit()
{
	++countES;

}

void EarthSoldier::Attack(Unit*AS)
{
	
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AS->GetHealth());
	AS->TakeDamage(Damage);

}

int EarthSoldier::GetCount()
{
	return countES;
}

EarthSoldier::~EarthSoldier()
{
	--countES;
}

