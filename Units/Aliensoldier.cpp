#include "AlienSoldier.h"

string AlienSoldier::UnitType()
{
	return "AlienSoldier";
}

AlienSoldier::AlienSoldier() :Unit()
{


}

void AlienSoldier::Attack(Unit*ES)
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(ES->GetHealth());
	ES->TakeDamage(Damage);
	

}

