#include "EarthTank.h"
int EarthTank::countET = 0;
EarthTank::EarthTank():Unit()
{
	++countET;
}

void EarthTank::Attack(Unit*AM)
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AM->GetHealth());
	AM->TakeDamage(Damage);

}

int EarthTank::GetCount()
{
	return countET;
}

EarthTank::~EarthTank()
{
	--countET;
}
