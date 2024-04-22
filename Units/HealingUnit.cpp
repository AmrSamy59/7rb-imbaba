#include "HealingUnit.h"
#include"../Game.h"
HealingUnit::HealingUnit(Game* gPtr, int id, int Tj, float health, float power, int AC):Unit(Unit::HU, gPtr, id, Tj, health, power, AC) {


}
void HealingUnit::Attack(Unit*dummy)
{
	Game* ptr = this->Getgameptr();
	LinkedQueue<Unit*>temp;

	for (int i = 0; i < this->GetAttackCapacity(); i++) {
		
		Unit* p = ptr->GetFromUML(); /// dequeue from UML
		if (p == NULL) {
			break;
		}
		float heal = (this->GetPower() * this->GetHealth() / 100) / sqrtf(p->GetHealth());
		p->Sethealth(heal + p->GetHealth());
		if (p->GetHealth() > 0.2 * p->GetintialHeal()) {
			ptr->addUnit(p);
			//p->SetHealtime(ptr->GetCurrentTimeStep());
		}
		else {
			temp.enqueue(p);
			
		}


	}
	while (!temp.isEmpty())
	{
		Unit* p;
		temp.dequeue(p);
		ptr->AddToUML(p);

	}


	//ptr->AddToKilledList(this); /// make in the earth army attack pop from stack killed your self
	return;
}
