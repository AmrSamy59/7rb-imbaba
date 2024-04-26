#include "AlienMonster.h"
#include"../Game.h"

AlienMonster::AlienMonster(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::AM, gPtr, id, Tj, health, power, AC)
{
	
}

bool AlienMonster::Attack()
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(EM->GetHealth());
	EM->TakeDamage(Damage);
	return true;
}



