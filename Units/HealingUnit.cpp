#include "HealingUnit.h"
#include"../Game.h"
HealingUnit::HealingUnit(Game* gPtr, int id, int Tj, float health, float power, int AC):Unit(Unit::HU, gPtr, id, Tj, health, power, AC) {


}
bool HealingUnit::Attack()
{
	Game* gptr = this->GetGamePtr();
	LinkedQueue<Unit*>temp;
	bool worked = false;
	for (int i = 0; i < this->GetAttackCapacity(); i++) {
		
		Unit* p = gptr->GetFromUML(); /// dequeue from UML
		if (p == NULL) {
			break;
		}
		worked = true;
		float heal = (this->GetPower() * this->GetHealth() / 100) / sqrtf(p->GetHealth());
		if(p->GetInfected())
			heal = 0.5 * heal;
		p->Sethealth(heal + p->GetHealth());
		if (p->GetHealth() > 0.2 * p->GetintialHeal()) {
			gptr->addUnit(p);
			if (p->getType() == Unit::ES) {
				p->SetImmune();
				p->SetInfected(false);
			}

			/////////////// check type for solider and use
			if (p->getIsHealed() == false) {
				p->SetIsHealed(true);
				gptr->IncrementHealedUnitCount();
			}
			//p->SetHealtime(ptr->GetCurrentTimeStep());
		}
		else {
			temp.enqueue(p);
			
		}


	}

	if (!temp.isEmpty())
		PrintAttackList(temp, "heals");

	while (!temp.isEmpty())
	{
		Unit* p;
		temp.dequeue(p);
		gptr->ReturnToUML(p);
		/// make function for return to uml replace adduml

	}


	if(worked)
		gptr->AddToKilledList(this); /// make in the earth army attack pop from stack killed your self
	return worked;
}
