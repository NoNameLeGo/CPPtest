#pragma once
#include<iostream>
#include<string>
using namespace std;

class VRCharacter {
private:
	string name;
	int health;
	int maxHealth;
	int attack;

public:
	void init(string n);
	void takeDamage(int dmg);
	void heal(int amount);
	int getHealthPercent();
	void displayStatus();



};
