#include <iostream>
#include <string>
using namespace std;

// 定义基类 Student
class Student {
protected: // 根据派生类能访问 num 和 name 推断，这里应该是 protected
    int num;
    string name;
    char sex;

public:
    void get_value() {
        cout << "请输入学生学号、姓名和性别（用F和M表示）：" << endl;
        cin >> num >> name >> sex;
    }

    void display() {
        cout << "学号: " << num << "\t 姓名: " << name << "\t 性别: " << sex << endl;
    }
};

// 定义派生类 Student1
class Student1 : public Student {
private:
    int age;
    string addr;

public:
    void get_value_1() {
        cout << "请输入学生年龄、宿舍号：" << endl;
        cin >> age >> addr;
    }

    void display1() {
        // cout << num << name << sex << endl; // 原图中被注释掉的代码
        cout << "年龄: " << age << "\t 宿舍号: " << addr << endl;
    }
};

int main() {
    Student1 stu;

    stu.get_value();
    stu.get_value_1();
    stu.display();
    stu.display1();

    return 0;
}