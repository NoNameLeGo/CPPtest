#include <iostream>
#include <string>

using namespace std;

// 声明基类 Student
class Student{
public:
    Student(int, string, float); // 声明构造函数
    void display();              // 声明输出函数
protected:                       // 受保护成员，派生类可以访问
    int num;
    string name;
    float score;
};

// Student 类成员函数的实现
Student::Student(int n, string nam, float s) // 定义构造函数
{
    num = n;
    name = nam;
    score = s;
}

void Student::display() // 定义输出函数
{
    cout << "num:" << num << "\n name:" << name << "\n score:" << score << endl;
}

// 声明公用派生类 Graduate
class Graduate : public Student {
public:
    Graduate(int, string, float, float); // 声明构造函数
    void display();                      // 与基类的输出函数同名
private:
    float wage;
};

// Graduate 类成员函数的实现
Graduate::Graduate(int n, string nam, float s, float w) : Student(n, nam, s), wage(w) {}

void Graduate::display() // 定义输出函数
{
    cout << "num:" << num << "\n name:" << name << "\n score:" << score
         << "\n wage=" << wage << endl;
}


// 主函数
int main() {
    Student stud1(1001, "Li", 87.5);           // 定义 Student 类对象 stud1
    Graduate grad1(2001, "Wang", 98.5, 1200);  // 定义 Graduate 类对象 grad1
    
    Student* pt = &stud1;                      // 定义指向基类对象的指针变量 pt，指向 stud1
    pt->display();                             // 输出 Student(基类) 对象 stud1 中的数据
    pt = &grad1;                               // pt 指向 Graduate 类对象 grad1
    pt->display();                             // 希望输出 Graduate 类对象 grad1 中的数据
    
    return 0;
}
