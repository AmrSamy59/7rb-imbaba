#include "AlienMonster.h"
#include"../Game.h"

AlienMonster::AlienMonster(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::AM, gPtr, id, Tj, health, power, AC)
{
	
}

bool AlienMonster::Attack()
{
	// Attacks Tanks & ES
	Game* gptr = this->GetGamePtr();

	LinkedQueue<Unit*> et_temp;
	LinkedQueue<Unit*> es_temp;

	int cap = this->GetAttackCapacity();
	int f_cap = cap / 2;
	int s_cap = cap - f_cap;
	if (f_cap == 0) // to keep the order
	{
		f_cap = s_cap;
		s_cap = 0;
	}

	// get units
	for (int i = 0; i < f_cap; i++) {
		Unit* p;
		p = gptr->PickEarthUnit(Unit::ET);
		if (p) {
			et_temp.enqueue(p);
		}
	}
	for (int i = 0; i < s_cap; i++) {
		Unit* p;
		if (i % 2 == 0) {
			p = gptr->PickEarthUnit(Unit::ES);
			if (p) {
				es_temp.enqueue(p);
			}
		}
		else
		{
			p = gptr->PickAllyUnit();
			if (!p) {
				p = gptr->PickEarthUnit(Unit::ES);
			}
			if (p) {
				es_temp.enqueue(p);
			}

		}

	}

	if (!et_temp.isEmpty())
		PrintAttackList(et_temp);
	if (!es_temp.isEmpty())
		PrintAttackList(es_temp);

	while (!et_temp.isEmpty())
	{
		Unit* ET;
		et_temp.dequeue(ET);

		float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(ET->GetHealth());
		ET->TakeDamage(Damage);
		if (ET->GetHealth() <= 0.0) {
			gptr->AddToKilledList(ET);
		}
		else if (ET->GetHealth() > 0 && ET->GetHealth() < 0.2 * ET->GetintialHeal())
		{
			gptr->AddToUML(ET);
		}
		else
		{
			gptr->ReturnEarthUnit(ET);
		}

	}

	while (!es_temp.isEmpty())
	{
		Unit* ES;
		es_temp.dequeue(ES);

		float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(ES->GetHealth());
		ES->TakeDamage(Damage);
		if (ES->GetHealth() <= 0.0) {
			gptr->AddToKilledList(ES);
		}
		else if (ES->getType() == Unit::ES && ES->GetHealth() > 0 && ES->GetHealth() < 0.2 * ES->GetintialHeal())
		{
			gptr->AddToUML(ES);
		}
		else
		{
			if (ES->getType() == Unit::ES)
				gptr->ReturnEarthUnit(ES);
			else
			{
				gptr->ReturnAllyUnit(ES);
			}
		}

	}


	return true;
}



