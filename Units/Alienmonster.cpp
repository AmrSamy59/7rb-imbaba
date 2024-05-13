#include "AlienMonster.h"
#include"../Game.h"

AlienMonster::AlienMonster(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::AM, gPtr, id, Tj, health, power, AC)
{
	
}

bool AlienMonster::Attack()
{
	// Attacks Tanks & ES
	Game* gptr = this->GetGamePtr();

	LinkedQueue<Unit*> temp;

	Unit* p;
	// get units
	for (int i = 0; i < this->GetAttackCapacity(); i++) {
		if (i % 2 == 0) {
			p = gptr->PickEarthUnit(Unit::ET);
			if (!p) {
				p = gptr->PickAllyUnit();
			}
			if (!p) {
				p = gptr->PickEarthUnit(Unit::ES);
			}
			
		}
		else
		{
			p = gptr->PickAllyUnit();
			if (!p) {
				p = gptr->PickEarthUnit(Unit::ES);
			}
			if (!p) {
				p = gptr->PickEarthUnit(Unit::ET);
			}
		}
		if (p) {
			temp.enqueue(p);
		}
	}

	

	LinkedQueue<Unit*> temp_attacked;
	LinkedQueue<Unit*> temp_infected;

	while (!temp.isEmpty())
	{
		Unit* unit;
		temp.dequeue(unit);

		float Damage = ((this->GetPower()) * (this->GetHealth() / 100)) / sqrt(unit->GetHealth());
		if (unit->getType() == Unit::ES) {
			double infectionProb = gptr->GetInfectionProb();
			double prob = rand() % 100;
			if (prob <= infectionProb && !unit->IsInfected() && !unit->GetImmunity()) {
				unit->SetInfected(true);
				temp_infected.enqueue(unit);
			}
			else
			{
				unit->TakeDamage(Damage);
				temp_attacked.enqueue(unit);
			}
		}
		else
		{
			unit->TakeDamage(Damage);
			temp_attacked.enqueue(unit);
		}

		if (unit->GetHealth() <= 0.0) {
			gptr->AddToKilledList(unit);
		}
		else if ((unit->getType() == Unit::ES || unit->getType() == Unit::ET) && unit->GetHealth() > 0 && unit->GetHealth() < 0.2 * unit->GetintialHeal())
		{
			gptr->AddToUML(unit);
		}
		else
		{
			if (unit->getType() == Unit::ES || unit->getType() == Unit::ET)
				gptr->ReturnEarthUnit(unit);
			else
			{
				gptr->ReturnAllyUnit(unit);
			}
		}
	}

	if (!temp_attacked.isEmpty())
		PrintAttackList(temp_attacked);

	if (!temp_infected.isEmpty())
		PrintAttackList(temp_infected, "infects");

	return true;
}



