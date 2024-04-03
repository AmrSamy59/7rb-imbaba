#include "AlienMonster.h"
int AlienMonster::countAM = 0;
AlienMonster::AlienMonster() :Unit()
{
	countAM++;
}

void AlienMonster::Attack(Unit* EM)
{
	float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(EM->GetHealth());
	EM->TakeDamage(Damage);

}

int AlienMonster::GetCount() const
{
	return countAM;
}

AlienMonster::~AlienMonster()
{
	--countAM;
}

