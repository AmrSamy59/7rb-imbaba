#include "EarthGunnery.h"
int EarthGunnery::countEG = 0;
EarthGunnery::EarthGunnery() :Unit()
{
	countEG++;
}

void EarthGunnery::Attack(Unit* AD)
{

	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AD->GetHealth());	
	AD->TakeDamage(Damage);

}

int EarthGunnery::GetCount()
{
	return countEG ;
}

EarthGunnery::~EarthGunnery()
{
	--countEG;
}

