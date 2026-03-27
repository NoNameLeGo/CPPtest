#include <iostream>
#include"VRCharacter.h"

using namespace std;



int main()
{
	VRCharacter character;
	cout << "对象名调用：" << endl;
	character.init("zhangsan");
	character.displayStatus();

	character.takeDamage(20);
	character.displayStatus();

	character.heal(10);
	character.displayStatus();

	cout << "指针调用：" << endl;
	VRCharacter ch2;
	VRCharacter* p2 = &ch2;

	p2->init("Steven");
	p2->displayStatus();

	p2->takeDamage(30);
	p2->displayStatus();

	p2->heal(15);
	p2->displayStatus();

	cout << "引用调用：" << endl;
	VRCharacter ch3;
	ch3.init("Alice");
	ch3.displayStatus();

	VRCharacter& ref3 = ch3;
	ref3.takeDamage(25);
	ref3.displayStatus();
	ref3.heal(20);
	ref3.displayStatus();

	cout << "最终状态：" << endl;
	cout << " 第一个: " << character.getHealthPercent() << "%" << endl;
	cout << " 第二个: " << p2->getHealthPercent() << "%" << endl;
	cout << " 第三个: " << ref3.getHealthPercent() << "%" << endl;


	return 0;
}
