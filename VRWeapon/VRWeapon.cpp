#include <iostream>
#include <string>
using namespace std;

class VRWeapon {
private:
    string name;
    int damage;

public:
    VRWeapon() : name("未知武器"), damage(0) {}
    VRWeapon(string n, int d) : name(n), damage(d) {}
    void attack();
    void show();
};

void VRWeapon::attack() {
    cout << "使用" << name << "攻击，造成" << damage << "点伤害！" << endl;
}

void VRWeapon::show() {
    cout << "武器：" << name << "，伤害：" << damage << endl;
}

int main()
{
    cout << "=== VR武器库 ===" << endl;
    cout << endl;
    cout << "武器列表：" << endl;
    
    VRWeapon weapons[3] = {
        VRWeapon("剑", 50),
        VRWeapon("弓", 35),
        VRWeapon("法杖", 45)
    };
    
    for (int i = 0; i < 3; i++) {
        weapons[i].show();
    }
    
    cout << "开始攻击：" << endl;
    cout << endl;
    for (int i = 0; i < 3; i++) {
        weapons[i].attack();
    }
    
    return 0;
}
