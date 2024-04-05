#include "Unit.h"

Unit::Unit(UnitType uType, Game* gPtr, int id , int Tj , float health , float power , int AC)
{
	type = uType;
	ID = id;
	JoinTime = Tj;
	Health = health;
	Power = power;
	AttackCapacity = AC;
	GamePtr = gPtr;
}

//void Unit::SetID(int id)
//{
//	// don't change the id after you get it from file and used this function
//	ID = id;
//}

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

void Unit::Sethealth(float h)
{
	Health = h;
}

float Unit::GetHealth() const
{
	return Health;
}

void Unit::TakeDamage(float d)
{
	if (Health <= 0)
		return;
else {
	Health = Health - d;
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

Unit::UnitType Unit::getType()
{
	return type;
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
