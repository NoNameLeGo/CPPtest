#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int id;

public:
    Student(string n, int i) : name(n), id(i) {}
    void showBasic() {
        cout << "姓名: " << name << ", 学号: " << id << endl;
    }
};

class Postgraduate : public Student {
private:
    string researchField;

public:
    Postgraduate(string n, int i, string field) : Student(n, i), researchField(field) {}
    void showAll() {
        showBasic();
        cout << "研究方向: " << researchField << endl;
    }
    void setField(string field) {
        researchField = field;
    }
};

int main() {
    Postgraduate pg("张三", 2021001, "计算机视觉");
    
    cout << "=== 初始信息 ===" << endl;
    pg.showAll();
    
    pg.setField("虚拟现实");
    
    cout << "=== 修改后信息 ===" << endl;
    pg.showAll();
    
    return 0;
}