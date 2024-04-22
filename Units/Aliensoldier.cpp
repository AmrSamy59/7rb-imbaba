#include "AlienSoldier.h"
#include"../Game.h"
AlienSoldier::AlienSoldier(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::AS, gPtr, id, Tj, health, power, AC)
{


}

void AlienSoldier::Attack(Unit*ES)
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(ES->GetHealth());
	ES->TakeDamage(Damage);
	

}

