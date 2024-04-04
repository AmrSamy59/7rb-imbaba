#include "AlienMonster.h"

string AlienMonster::UnitType()
{
	return "AlienMonster";
}

AlienMonster::AlienMonster() : Unit()
{
	
}

void AlienMonster::Attack(Unit* EM)
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(EM->GetHealth());
	EM->TakeDamage(Damage);

}



