#include "AlienSoldier.h"
#include"../Game.h"
AlienSoldier::AlienSoldier(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::AS, gPtr, id, Tj, health, power, AC)
{


}

bool AlienSoldier::Attack()
{
	
	Game* gptr = this->GetGamePtr();
	LinkedQueue<Unit*> temp; /// dynamic list to delete it after finish
	for (int i = 0; i < this->GetAttackCapacity(); i++) {
		Unit* p;
		p = gptr->PickEarthUnit(Unit::ES);
		if (p) {
			temp.enqueue(p);
		}
	}

	if(!temp.isEmpty())
		PrintAttackList(temp);

	while (!temp.isEmpty())
	{
		Unit* ES;
		temp.dequeue(ES);

		float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(ES->GetHealth());
		ES->TakeDamage(Damage);
		if (ES->GetHealth() <= 0.0) {
			gptr->AddToKilledList(ES);
		}
		else if(ES->GetHealth()>0 && ES->GetHealth()<0.2*ES->GetintialHeal())
		{
			gptr->AddToUML(ES);
		}
		else
		{
			gptr->ReturnEarthUnit(ES);
		}

	}

	return true;

}

