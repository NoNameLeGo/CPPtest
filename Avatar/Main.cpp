#include <iostream>
#include <string>

using namespace std;

class Avatar {
private:
	string name;
	double height;

public:
	void setName();
	void showInfo();
	Avatar(string n = "Player", double h = 1.7) : name(n), height(h) {}
};

void Avatar::setName() {
	cout << "请输入虚拟化身的名字: ";
	cin >> name;
}

void Avatar::showInfo() {
	cout << "虚拟化身名字: " << name << ", 身高: " << height << "米" << endl;
}

int main() {
	Avatar a1;
	a1.showInfo();

	Avatar a2;
	a2.setName();
	a2.showInfo();

	Avatar a3("CustomPlayer", 1.85);
	a3.showInfo();

	return 0;
}