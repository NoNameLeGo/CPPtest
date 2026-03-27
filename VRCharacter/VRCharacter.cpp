#include"VRCharacter.h"


void VRCharacter::init(string n) {
	name = n;
	health = 100;
	maxHealth = 100;
	attack = 10;
}

void VRCharacter::takeDamage(int dmg) {
	if(dmg>0) {
		health -= dmg;
		if (health < 0) health = 0;
		cout << name << " 受到 " << dmg << " 点伤害！" << endl;
	}
	else {
		cout << "伤害值必须大于0！" << endl;
	}
}

void VRCharacter::heal(int amount) {
	if (amount > 0) {
		health += amount;
		if (health > maxHealth) health = maxHealth;
		cout << name << " 治疗了 " << amount << " 点生命！" << endl;
	}
	else {
		cout << "治疗值必须大于0！" << endl;
	}
}

void VRCharacter::displayStatus() {
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << "角色: " << name << endl;
	cout << "生命值: " << health << "/" << maxHealth << endl;
	cout << "血量百分比: " << getHealthPercent() << "%" << endl;
	cout << "攻击力: " << attack << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
}

int VRCharacter::getHealthPercent() {
	return (health * 100) / maxHealth;
}

