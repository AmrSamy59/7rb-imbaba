#pragma once
#include<iostream>
#include "../Game.h"

using namespace std;
class Unit
{
private:
	int ID;
	int joinTime; // Tj
	float health;
	float power;
	int attackCapacity; // AC
	Game* GamePtr;
public:
	Unit(int id=0,int Tj=0, float health=0.0,float power= 0.0,int AC=0, Game* gPtr);
	//void SetID(int i);
	int GetID() const;
	void SetJoinTime(int t);
	int GetJoinTime() const;
	void Sethealth(int h);
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

	bool operator==(Unit* unit);
	

};

