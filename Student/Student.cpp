#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

// 类：为避免与结构体重名，取名为 StudentClass
class StudentClass {
private:
    int id;
    string name;
    int age;

public:
    void setInfo(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }

    void showInfo() {
        cout << "学号：" << id << "，姓名：" << name << "，年龄：" << age << endl;
    }
};

int main()
{
    Student stu1 = {2025001, "张三", 19};
    cout << "结构体方式：" << endl;
    cout << "学号：" << stu1.id << "，姓名：" << stu1.name << "，年龄：" << stu1.age << endl;
    cout << endl;

    StudentClass stu2;
    stu2.setInfo(2025002, "李四", 20);
    cout << "类方式：" << endl;
    stu2.showInfo();

    return 0;
}