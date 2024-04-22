#include "EarthGunnery.h"
#include"../Game.h"
EarthGunnery::EarthGunnery(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::EG, gPtr, id, Tj, health, power, AC)
{

}

void EarthGunnery::Attack(Unit* AD)
{

	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AD->GetHealth());	
	AD->TakeDamage(Damage);

}

