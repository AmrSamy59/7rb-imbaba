#include "EarthSoldier.h"
#include"../Game.h"
EarthSoldier::EarthSoldier(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::ES, gPtr, id, Tj, health, power, AC)
{


}

bool EarthSoldier::Attack()
{
	Game* gptr = this->GetGamePtr();
	LinkedQueue<Unit*> temp; /// dynamic list to delete it after finish
	for (int i = 0; i < this->GetAttackCapacity(); i++) {
		Unit* p;
		if (GetInfected())
			p = gptr->PickEarthUnit(Unit::ES);
		else
			p = gptr->pickAlienunit(Unit::AS);
		if (p) {
			temp.enqueue(p);
		}
	}

	if (!temp.isEmpty())
		PrintAttackList(temp);

	while (!temp.isEmpty())
	{
		Unit* AS;
		temp.dequeue(AS);

		float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AS->GetHealth());
		AS->TakeDamage(Damage);
		if (AS->GetHealth() <= 0.0) {
			gptr->AddToKilledList(AS);
		}
		else
		{
			if(AS->getType() == Unit::AS)
				gptr->ReturnAlienUnit(AS);
			else
			{
				if (AS->GetHealth() > 0 && AS->GetHealth() < 0.2 * AS->GetintialHeal())
				{
					gptr->AddToUML(AS);
				}
				else
					gptr->ReturnEarthUnit(AS);
			}
		}
		
	}



	
	
	return true;
}

