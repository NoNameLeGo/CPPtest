#ifndef VRCHARACTER_H
#define VRCHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class VRCharacter {
private:
    string name;
    int health;
    int maxHealth;
    int attack;

public:
    VRCharacter();
    VRCharacter(string n, int h, int m, int a);
    
    void init(string n);
    void init(string n, int h, int m, int a);
    
    void takeDamage(int dmg);
    void heal(int amount);
    int getHealthPercent();
    void displayStatus();
    
    string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getAttack() const;
};

#endif
