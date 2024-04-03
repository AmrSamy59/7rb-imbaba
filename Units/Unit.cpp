#include "Unit.h"

Unit::Unit(int id , int Tj , float health , float power , int AC )
{
	ID = id;
	joinTime = Tj;
	health = health;
	power = power;
	attackCapacity = AC;
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
	joinTime = t;
}

int Unit::GetJoinTime() const
{
	return joinTime;
}

void Unit::Sethealth(int h)
{
	health = h;
}

float Unit::GetHealth() const
{
	return health;
}

void Unit::TakeDamage(float d)
{
	if (health <= 0)
		return;
else {
	health = health - d;
}
}


void Unit::SetPower(float p)
{
	power = p;
}

float Unit::GetPower() const
{
	return power;
}

void Unit::SetAttackCapacity(int ac)
{
	attackCapacity = ac;
}

int Unit::GetAttackCapacity() const
{
	return attackCapacity;
}


void Unit::PrintInfo() const
{
	cout << "ID : " << ID << " | " << "Tj : " << joinTime << " | " << "health : " << health << " | " << " power : " << power << endl;
}

bool Unit::IsDead() const
{
	if (health <= 0) {
		return true;
	}
	else
	return false;
}

