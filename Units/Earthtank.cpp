#include "EarthTank.h"

#include"../Game.h"
EarthTank::EarthTank(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::ET, gPtr, id, Tj, health, power, AC)
{
}

bool EarthTank::Attack()
{
	Game* gptr = this->GetGamePtr();
	LinkedQueue<Unit*> temp;
	Unit* p = nullptr;
	for (int i = 0; i < this->GetAttackCapacity(); i++)
	{
		if(i%2){
			if(gptr->CanEtAttackAs()){
				p = gptr->pickAlienunit(Unit::AS);
				if(!p) p = gptr->pickAlienunit(Unit::AM);
			}
			else p = gptr->pickAlienunit(Unit::AM);
		}
		else{
			p = gptr->pickAlienunit(Unit::AM);
			if(!p && gptr->CanEtAttackAs()) p = gptr->pickAlienunit(Unit::AS);
		}
		if(p) temp.enqueue(p);
	}
	if (!temp.isEmpty())
		PrintAttackList(temp);
	while (!temp.isEmpty())
	{
		Unit* AM;
		temp.dequeue(AM);
		float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AM->GetHealth());
		AM->TakeDamage(Damage);
		if (AM->GetHealth() <= 0.0)
			gptr->AddToKilledList(AM);
		else
			gptr->ReturnAlienUnit(AM);
	}
	return true;
}

