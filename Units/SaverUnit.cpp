#include "SaverUnit.h"
#include"../Game.h"
SaverUnit::SaverUnit(Game* gPtr, int id, int Tj, float health, float power, int AC) :Unit(Unit::SU, gPtr, id, Tj, health, power, AC) {


}

bool SaverUnit::Attack()
{
	Game* gptr = this->GetGamePtr();
	LinkedQueue<Unit*>temp;
	for (int i = 0; i < this->GetAttackCapacity(); i++) {
		Unit* p;
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
			gptr->ReturnAlienUnit(AS);
		}

	}





	return true;
}

