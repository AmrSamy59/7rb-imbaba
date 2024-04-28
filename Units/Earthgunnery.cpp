#include "EarthGunnery.h"
#include"../Game.h"
EarthGunnery::EarthGunnery(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::EG, gPtr, id, Tj, health, power, AC)
{

}

bool EarthGunnery::Attack()
{
	Game* gptr = this->GetGamePtr();
	LinkedQueue<Unit*> temp; /// dynamic list to delete it after finish
	////////////////////// AM attack ////////////////////////////////////////////////
	for (int i = 0; i < this->GetAttackCapacity(); i++) {
		Unit* p;
		p = gptr->pickAlienunit(Unit::AM);
		if (p) {
			temp.enqueue(p);
		}
	}

	if (!temp.isEmpty())
		PrintAttackList(temp);

	while (!temp.isEmpty())
	{
		Unit* AM;
		temp.dequeue(AM);

		float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(AM->GetHealth());
		AM->TakeDamage(Damage);
		if (AM->GetHealth() <= 0.0) {
			gptr->AddToKilledList(AM);
		}
		else
		{
			gptr->ReturnAlienUnit(AM);
		}

	}

	////////////////////// AM attack ////////////////////////////////////////////////
	return true;
}

