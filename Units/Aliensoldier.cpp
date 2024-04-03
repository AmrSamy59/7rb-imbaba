#include "AlienSoldier.h"
int AlienSoldier::countAS = 0;
AlienSoldier::AlienSoldier() :Unit()
{
	countAS++;

}

void AlienSoldier::Attack(Unit*ES)
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(ES->GetHealth());
	ES->TakeDamage(Damage);
	

}


int AlienSoldier::GetCount()
{
	return countAS;
}

AlienSoldier::~AlienSoldier()
{
	--countAS;
}
