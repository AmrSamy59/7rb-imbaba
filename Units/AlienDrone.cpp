#include "AlienDrone.h"
#include"../Game.h"
AlienDrone::AlienDrone(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::AD, gPtr, id, Tj, health, power, AC)
{

}
bool AlienDrone::Attack()
{
	Game* gptr = this->GetGamePtr();
	LinkedQueue<Unit*> temp;
	for (int i = 0; i < this->GetAttackCapacity() ; i++)
	{
		Unit* p;
		if(i % 2 == 0){
			p = gptr->PickEarthUnit(Unit::ET);
			if(!p) p = gptr->PickEarthUnit(Unit::EG);
		}
		else{
			p = gptr->PickEarthUnit(Unit::EG);
			if(!p) p = gptr->PickEarthUnit(Unit::ET);
		}
		if(p) temp.enqueue(p);
	}
	if (!temp.isEmpty())
		PrintAttackList(temp);
	while (!temp.isEmpty()) {
		Unit* target;
		temp.dequeue(target);
		float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(target->GetHealth());
		target->TakeDamage(Damage);
		if (target->GetHealth() <= 0.0)
			gptr->AddToKilledList(target);
		else if (target->getType() == Unit::ET &&
			target->GetHealth() > 0 &&
			target->GetHealth() < 0.2 * target->GetintialHeal())
			gptr->AddToUML(target);
		else
			gptr->ReturnEarthUnit(target);
	}
	return true;
}


