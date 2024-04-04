#pragma once
#include<iostream>

class Game;

using namespace std;
class Unit
{
private:
	int ID;
	int JoinTime; // Tj
	float Health;
	float Power;
	int AttackCapacity; // AC
	Game* GamePtr;
public:
	Unit(Game* gPtr=nullptr, int id=0,int Tj=0, float health=0.0,float power= 0.0,int AC=0);
	//void SetID(int i);
	int GetID() const;
	void SetJoinTime(int t);
	int GetJoinTime() const;
	void Sethealth(float h);
	float GetHealth() const;
   //bool Heal();
	void TakeDamage(float d);
	void SetPower(float p);
	float GetPower() const;
	void SetAttackCapacity(int ac);
	int GetAttackCapacity() const;
	void PrintInfo() const;
	bool IsDead() const;
	virtual void Attack(Unit*ptr) = 0 ;
	virtual string UnitType() = 0;
	bool operator==(Unit* unit);
	friend ostream& operator<<(ostream& COUT, const Unit* obj);
	

};

