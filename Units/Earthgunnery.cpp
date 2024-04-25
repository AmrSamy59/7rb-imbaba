#include "EarthGunnery.h"
#include"../Game.h"
EarthGunnery::EarthGunnery(Game* gPtr, int id, int Tj, float health, float power, int AC) : Unit(Unit::EG, gPtr, id, Tj, health, power, AC)
{

}

bool EarthGunnery::Attack(Unit* dummy)
{
	Game* gptr = this->Getgameptr();
	LinkedQueue<Unit*>* temp = new LinkedQueue<Unit*>; /// dynamic list to delete it after finish
	for (int i = 0; i < this->GetAttackCapacity(); i++) {
		Unit* p;
		p = gptr->pickAlienunit(Unit::AM);
		if (p) {
			temp->enqueue(p);
		}
	}
	while (!temp->isEmpty())
	{
		Unit* AM;
		temp->dequeue(AM);

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
	delete temp;
	return true;
}

