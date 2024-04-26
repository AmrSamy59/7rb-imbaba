#include "EarthSoldier.h"
#include"../Game.h"
EarthSoldier::EarthSoldier(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::ES, gPtr, id, Tj, health, power, AC)
{


}

bool EarthSoldier::Attack()
{
	Game* gptr = this->Getgameptr();
	LinkedQueue<Unit*>* temp = new LinkedQueue<Unit*>; /// dynamic list to delete it after finish
	for (int i = 0; i < this->GetAttackCapacity(); i++) {
		Unit* p;
		p=gptr->pickAlienunit(Unit::AS);
		if (p) {
			temp->enqueue(p);
		}
	}
	while (!temp->isEmpty())
	{
		Unit* AS;
		temp->dequeue(AS);

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

	delete temp;



	
	
	return true;
}

