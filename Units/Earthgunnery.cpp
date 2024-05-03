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
		if(i%3 == 0){
			p = gptr->pickAlienunit(Unit::AM);
			if(!p) gptr->pickAlienunit(Unit::AD);
		}
		else if(i%3 == 1){
			p = gptr->pickAlienunit(Unit::AD);
			if(!p) gptr->pickAlienunit(Unit::AM);
		}
		else {
			p = gptr->pickAlienunit(Unit::AD, true);
			if (!p) gptr->pickAlienunit(Unit::AM);
		}
		if (p) temp.enqueue(p);
	}
	if (!temp.isEmpty())
		PrintAttackList(temp);

	while (!temp.isEmpty())
	{
		Unit* target;
		temp.dequeue(target);

		float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(target->GetHealth());
		target->TakeDamage(Damage);
		if (target->GetHealth() <= 0.0) {
			gptr->AddToKilledList(target);
		}
		else
		{
			gptr->ReturnAlienUnit(target);
		}

	}

	////////////////////// AM attack ////////////////////////////////////////////////
	return true;
}

