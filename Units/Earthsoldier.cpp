#include "EarthSoldier.h"
#include"../Game.h"
EarthSoldier::EarthSoldier(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::ES, gPtr, id, Tj, health, power, AC)
{


}

void EarthSoldier::Attack(Unit*AS)
{
	
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AS->GetHealth());
	AS->TakeDamage(Damage);

}

