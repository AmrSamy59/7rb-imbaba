#include "HealUnit.h"

HealUnit::HealUnit(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::HU, gPtr, id, Tj, health, power, AC)
{
		//AC stands for attack Cap -> please Osta Hany Modify this

		//Don't Ontr me Ablkash Plzzzzzzzzz

}
													//Modify this Osta
void HealUnit::Attack(Unit*AS)
{
	
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AS->GetHealth());
	AS->TakeDamage(Damage);

}