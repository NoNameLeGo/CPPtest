#include "VRCharacter.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== VR 角色战斗模拟 ===" << endl << endl;
    
    cout << "--- 方式1: 使用对象名调用 ---" << endl;
    VRCharacter hero1;
    hero1.init("勇者", 100, 100, 15);
    hero1.displayStatus();
    
    hero1.takeDamage(20);
    hero1.displayStatus();
    
    hero1.heal(30);
    hero1.displayStatus();
    
    cout << "\n--- 方式2: 使用指针调用 ---" << endl;
    VRCharacter* enemy = new VRCharacter();
    enemy->init("怪物", 80, 80, 12);
    enemy->displayStatus();
    
    enemy->takeDamage(25);
    enemy->displayStatus();
    
    cout << "\n--- 方式3: 使用引用调用 ---" << endl;
    VRCharacter ally("同伴", 90, 90, 10);
    ally.displayStatus();
    
    VRCharacter& refAlly = ally;
    refAlly.heal(20);
    refAlly.displayStatus();
    
    cout << "\n--- 战斗结果 ---" << endl;
    cout << hero1.getName() << " 的血量百分比: " << hero1.getHealthPercent() << "%" << endl;
    cout << enemy->getName() << " 的血量百分比: " << enemy->getHealthPercent() << "%" << endl;
    cout << ally.getName() << " 的血量百分比: " << ally.getHealthPercent() << "%" << endl;
    
    delete enemy;
    
    return 0;
}
