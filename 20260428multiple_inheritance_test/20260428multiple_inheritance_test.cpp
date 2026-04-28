#include <iostream>
#include <string>
using namespace std;

class Teacher {
protected:
    string name;
    int age;
    string title;
public:
    Teacher(string nam, int a, string t) {
        name = nam;
        age = a;
        title = t;
    }
    void display() {
        cout << "name:" << name << "\t age:" << age << "\ttitle:" << title << endl;
    }
};

class Student {
protected:
    string name1;
    char sex;
    float score;
public:
    Student(string na, char s, float sc) {
        name1 = na;
        sex = s;
        score = sc;
    }
    void display1() {
        cout << "name:" << name1 << "\t sex:" << sex << "\t score:" << score << endl;
    }
};

class Graduate : public Teacher, public Student {
private:
    float wage;
public:
    Graduate(string nam, int a, string t, string na, char s, float sc, float w)
        : Teacher(nam, a, t), Student(na, s, sc), wage(w) {
    }
    void show() {
        cout << "name:" << name << "\t age:" << age << "\t sex:" << sex << "\t score:" << score << "\t title:" << title << "\t wage:" << wage << endl;
    }
};

int main() {
    Graduate gra1("张丽", 21, "讲师", "张丽", 'F', 89.5, 1200);
    gra1.show();
    return 0;
}