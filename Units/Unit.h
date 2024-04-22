#pragma once
#include<iostream>

class Game;

using namespace std;
class Unit
{
public:
	enum UnitType { AD, AM, AS, EG, ES, ET, HU};
private:
	int ID;
	int JoinTime; // Tj
	float Health;
	float Power;
	int AttackCapacity; // AC
	UnitType type;
	Game* GamePtr;
public:
	Unit(UnitType uType, Game* gPtr, int id, int Tj, float health, float power, int AC);
	int GetID() const;
	void SetJoinTime(int t);
	int GetJoinTime() const;
	void Sethealth(float h);
	float GetHealth() const;
	void TakeDamage(float d);
	void SetPower(float p);
	float GetPower() const;
	void SetAttackCapacity(int ac);
	int GetAttackCapacity() const;
	void PrintInfo() const;
	bool IsDead() const;
	virtual void Attack(Unit*ptr) = 0 ;
	UnitType getType();
	bool operator==(Unit* unit);
	friend ostream& operator<<(ostream& COUT, const Unit* obj);
	

};

