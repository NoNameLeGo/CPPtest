#include <iostream>
using namespace std;
#include "Student.h"

void Student::SetInfo(string n, int a) {
	name = n;
	age = a;
}
void Student::DiplayInfo() {
	cout << "姓名：" << name << endl;
	cout << "年龄：" << age << endl;
};
