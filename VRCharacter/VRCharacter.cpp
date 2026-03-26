#include "VRCharacter.h"

VRCharacter::VRCharacter() : health(100), maxHealth(100), attack(10) {}

VRCharacter::VRCharacter(string n, int h, int m, int a) 
    : name(n), health(h), maxHealth(m), attack(a) {}

void VRCharacter::init(string n) {
    name = n;
    health = 100;
    maxHealth = 100;
    attack = 10;
}

void VRCharacter::init(string n, int h, int m, int a) {
    name = n;
    health = h;
    maxHealth = m;
    attack = a;
}

void VRCharacter::takeDamage(int dmg) {
    if (dmg > 0) {
        health -= dmg;
        if (health < 0) health = 0;
        cout << name << " 受到 " << dmg << " 点伤害！" << endl;
    } else {
        cout << "伤害值无效！" << endl;
    }
}

void VRCharacter::heal(int amount) {
    if (amount > 0) {
        health += amount;
        if (health > maxHealth) health = maxHealth;
        cout << name << " 恢复了 " << amount << " 点生命值！" << endl;
    } else {
        cout << "恢复值无效！" << endl;
    }
}

int VRCharacter::getHealthPercent() {
    return (health * 100) / maxHealth;
}

void VRCharacter::displayStatus() {
    cout << "-----------------------------" << endl;
    cout << "角色名称: " << name << endl;
    cout << "当前血量: " << health << "/" << maxHealth << endl;
    cout << "血量百分比: " << getHealthPercent() << "%" << endl;
    cout << "攻击力: " << attack << endl;
    cout << "-----------------------------" << endl;
}

string VRCharacter::getName() const {
    return name;
}

int VRCharacter::getHealth() const {
    return health;
}

int VRCharacter::getMaxHealth() const {
    return maxHealth;
}

int VRCharacter::getAttack() const {
    return attack;
}
