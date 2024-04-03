#include "Unit.h"

Unit::Unit(int id , int Tj , float health , float power , int AC )
{
	ID = id;
	Join_time = Tj;
	Health = health;
	Power = power;
	Attack_capacity = AC;
}

void Unit::Setid(int id)
{
	// don't change the id after you get it from file and used this function
	ID = id;
}

int Unit::Getid() const
{
	return ID;
}

void Unit::Set_Tj(int t)
{
	Join_time = t;
}

int Unit::Get_Tj() const
{
	return Join_time;
}

void Unit::Sethealth(int h)
{
	Health = h;
}

float Unit::Gethealth() const
{
	return Health;
}

void Unit::Health_decrease(float d)
{
	if (Health <= 0)
		return;
else {
	Health = Health - d;
}
}

void Unit::Setpower(float p)
{
	Power = p;
}

float Unit::Getpower() const
{
	return Power;
}

void Unit::Set_AC(int ac)
{
	Attack_capacity = ac;
}

int Unit::get_AC() const
{
	return Attack_capacity;
}


void Unit::print() const
{
	cout << "ID : " << ID << " | " << "Tj : " << Join_time << " | " << "Health : " << Health << " | " << " Power : " << Power << endl;
}

bool Unit::Isdead() const
{
	if (Health <= 0) {
		return true;
	}
	else
	return false;
}

