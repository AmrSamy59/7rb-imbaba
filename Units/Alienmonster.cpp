#include "AlienMonster.h"


AlienMonster::AlienMonster(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(AM, gPtr, id, Tj, health, power, AC)
{
	
}

void AlienMonster::Attack(Unit* EM)
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(EM->GetHealth());
	EM->TakeDamage(Damage);

}



