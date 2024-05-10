#pragma once
#include<iostream>
#include "../DS/Queues/LinkedQueue.h"
class Game;
using namespace std;
class Unit
{
public:

	enum UnitType { AD, AM, AS, EG, ES, ET, HU, SU, LastType };

private:
	int ID;
	int JoinTime; // Tj
	int FirstAttackTime; // Ta
	int DestructionTime; // Td
	int HealTime;  /// for healing unit phase 2
	float IHealth; /// for healing unit phase 2
	float Health;  
	float Power;
	int AttackCapacity; // AC
	bool IsHealed;
	UnitType type;
	Game* GamePtr;
public:
	Unit(UnitType uType, Game* gPtr, int id, int Tj, float health, float power, int AC);
	int GetID() const;
	void SetJoinTime(int t);
	int GetJoinTime() const;
	int GetFirstAttackTime() const;
	int GetDestructionTime() const;
	void SetDestructionTime(int t);
	void Sethealth(float h);
	float GetHealth() const;
	void TakeDamage(float d);
	void SetPower(float p);
	float GetPower() const;
	void SetAttackCapacity(int ac);
	int GetAttackCapacity() const;
	void SetHealtime(int t);
	int GetHealtime() const;
	void SetIsHealed(bool x);
	bool getIsHealed()const;
	void PrintInfo() const;
	bool IsDead() const;

	float GetintialHeal() const;
	Game* GetGamePtr();
	virtual bool Attack() = 0 ;
	void PrintAttackList(LinkedQueue<Unit*>& list, string custom_action="shots");
	UnitType getType();
	string getTypeString();
	bool operator==(Unit* unit);
	friend ostream& operator<<(ostream& COUT, const Unit* obj);
	

};

