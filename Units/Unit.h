#pragma once
#include<iostream>
using namespace std;
class Unit
{
private:
	int ID;
	int Join_time; // Tj
	float Health;
	float Power;
	int Attack_capacity; // AC
public:
	Unit(int id=0,int Tj=0, float health=0.0,float power= 0.0,int AC=0);  
	void Setid(int i);
	int Getid() const;
	void Set_Tj(int t);
	int Get_Tj() const;
	void Sethealth(int h);
	float Gethealth() const;
   //bool Health_increase();
	void Health_decrease(float d);
	void Setpower(float p);
	float Getpower() const;
	void Set_AC(int ac);
	int get_AC() const;
	void print() const;
	bool Isdead() const;
	virtual void Attack(Unit*ptr)= 0 ;
	

};

