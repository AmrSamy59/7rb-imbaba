#include "HealingUnit.h"
#include"../Game.h"
HealingUnit::HealingUnit(Game* gPtr, int id, int Tj, float health, float power, int AC):Unit(Unit::HU, gPtr, id, Tj, health, power, AC) {


}
bool HealingUnit::Attack()
{
	Game* gptr = this->GetGamePtr();
	LinkedQueue<Unit*> healed_temp;
	LinkedQueue<Unit*> back_temp;
	bool worked = false;
	for (int i = 0; i < this->GetAttackCapacity(); i++) {
		
		Unit* p = gptr->GetFromUML(); /// dequeue from UML
		if (p == NULL) {
			break;
		}
		worked = true;
		float heal = (this->GetPower() * this->GetHealth() / 100) / sqrtf(p->GetHealth());
		if (p->getType() == Unit::ES && p->IsInfected()) {
			heal = 0.5 * heal;
			p->SetImmune();
			p->SetInfected(false);
		}
		p->Sethealth(heal + p->GetHealth());

		healed_temp.enqueue(p);

		if (p->GetHealth() > 0.2 * p->GetintialHeal()) {
			gptr->addUnit(p);

			/////////////// check type for solider and use
			if (p->getIsHealed() == false) {
				p->SetIsHealed(true);
				gptr->IncrementHealedUnitCount();
			}
			//p->SetHealtime(ptr->GetCurrentTimeStep());
		}
		else {
			back_temp.enqueue(p);
			
		}


	}

	if (!healed_temp.isEmpty())
		PrintAttackList(healed_temp, "heals");

	Unit* p;
	while (healed_temp.dequeue(p));

	while (!back_temp.isEmpty())
	{
		Unit* p2;
		back_temp.dequeue(p2);
		gptr->ReturnToUML(p2);
		/// make function for return to uml replace adduml

	}


	if(worked)
		gptr->AddToKilledList(this); /// make in the earth army attack pop from stack killed your self

	return worked;
}
