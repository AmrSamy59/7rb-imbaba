#include "Unit.h"
#include"../Game.h"

Unit::Unit(UnitType uType, Game* gPtr, int id , int Tj , float health , float power , int AC)
{
	type = uType;
	ID = id;
	JoinTime = Tj;
	FirstAttackTime = -1; // Default Value until first hit
	DestructionTime = -1; // Default Value until death
	Health = health;
	IHealth = health;
	HealTime = Tj;
	Power = power;
	AttackCapacity = AC;
	GamePtr = gPtr;
	IsHealed = false;
}



int Unit::GetID() const
{
	return ID;
}

void Unit::SetJoinTime(int t)
{
	JoinTime = t;
}

int Unit::GetJoinTime() const
{
	return JoinTime;
}

int Unit::GetFirstAttackTime() const
{
	return FirstAttackTime;
}

int Unit::GetDestructionTime() const
{
	return DestructionTime;
}

void Unit::SetDestructionTime(int t)
{
	DestructionTime = t;
}

void Unit::Sethealth(float h)
{
	if (h >= IHealth)
	{
		Health = IHealth;
	}
	else
	Health = h;
}

float Unit::GetHealth() const
{
	return Health;
}

void Unit::TakeDamage(float d)
{
	if (FirstAttackTime == -1) {
		int timeStep = GetGamePtr()->GetCurrentTimeStep();
		FirstAttackTime = timeStep;
	}

	Health = Health - d;
	if (Health <= 0)
	{
		Health = 0;
		int timeStep = GetGamePtr()->GetCurrentTimeStep();
		DestructionTime = timeStep;
	}
		
}



void Unit::SetPower(float p)
{
	Power = p;
}

float Unit::GetPower() const
{
	return Power;
}

void Unit::SetAttackCapacity(int ac)
{
	AttackCapacity = ac;
}

int Unit::GetAttackCapacity() const
{
	return AttackCapacity;
}


void Unit::PrintInfo() const
{
	cout << "ID : " << ID << " | " << "Tj : " << JoinTime << " | " << "health : " << Health << " | " << " power : " << Power << endl;
}

bool Unit::IsDead() const
{
	if (Health <= 0) {
		return true;
	}
	else
	return false;
}

void Unit::SetHealtime(int t)
{
	HealTime = t;
}

int Unit::GetHealtime() const
{
	return HealTime;
}

void Unit::SetIsHealed(bool x)
{
	IsHealed = x;
}

bool Unit::getIsHealed() const
{
	return IsHealed;
}

float Unit::GetintialHeal() const
{
	return IHealth;
}



Game* Unit::GetGamePtr()
{
	return GamePtr;
}


void Unit::PrintAttackList(LinkedQueue<Unit*>& list, string custom_action)
{
	if (GamePtr->GetGameMode() != 'i') return;
	string s_type = getTypeString();
	// custom_action defaults to shots
	cout << endl << s_type << " " << ID << " " << custom_action << " [";
	list.Print();
	cout << "]" << endl;

}

Unit::UnitType Unit::getType()
{
	return type;
}

string Unit::getTypeString()
{
	switch (type) {
		case AD:
			return "AD";
		case AM:
			return "AM";
		case AS:
			return "AS";
		case EG:
			return "EG";
		case ES:
			return "ES";
		case ET:
			return "ET";
		case HU:
			return "HU";
	}
}

bool Unit::operator==(Unit* unit)
{
	return this->ID == unit->ID;
}

ostream& operator<<(std::ostream& COUT, const Unit* obj)
{
	COUT << obj->GetID();
	return COUT;
}
