#include <iostream>
#include <string>

using namespace std;

class Role {
protected:
    string name;
    int health;

public:
    Role(string n, int h) : name(n), health(h) {}
    virtual void attack(Role *tar) = 0;
    virtual void takeDamage(int dmg) = 0;
    virtual ~Role() {}
};

class Warrior : public Role {
public:
    Warrior(string n, int h) : Role(n, h) {}

    void attack(Role *tar) override {
        int dmg = 12;
        cout << name << "发起攻击，造成" << dmg << "点伤害" << endl;
        tar->takeDamage(dmg);
    }

    void takeDamage(int dmg) override {
        int actualDmg = dmg * 0.9;
        health -= actualDmg;
        cout << name << "減免伤害后实际受到" << actualDmg << "点，剩余血量：" << health << endl;
    }
};

class Archer : public Role {
public:
    Archer(string n, int h) : Role(n, h) {}

    void attack(Role *tar) override {
        int dmg = 14;
        cout << name << "发起攻击，造成" << dmg << "点伤害" << endl;
        tar->takeDamage(dmg);
    }

    void takeDamage(int dmg) override {
        health -= dmg;
        cout << name << "实际受到" << dmg << "点，剩余血量：" << health << endl;
    }
};

int main()
{
    Warrior warrior("铁甲战士", 100);
    Archer archer("精灵弓手", 90);

    Role* p1 = &warrior;
    Role* p2 = &archer;

    p1->attack(p2);
	cout << "----------------------------------------------" << endl;
    p2->attack(p1);

    return 0;
}