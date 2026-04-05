#include <iostream>
#include <string>
using namespace std;

class VRExperience {
private:
    string name;
    int duration;
    int price;

public:
    VRExperience();
    VRExperience(string n, int d, int p);
    ~VRExperience();
    void display();
    int getPrice();
};

VRExperience::VRExperience() : name("基础体验"), duration(10), price(30) {
    cout << "【创建】默认体验项目：基础体验" << endl;
}

VRExperience::VRExperience(string n, int d, int p) : name(n), duration(d), price(p) {
    cout << "【创建】体验项目：" << name << "，" << duration << "分钟，" << price << "元" << endl;
}

VRExperience::~VRExperience() {
    cout << "【删除】体验项目：" << name << "已下架" << endl;
}

void VRExperience::display() {
    cout << "项目：" << name << "，时长：" << duration << "分钟，价格：" << price << "元" << endl;
}

int VRExperience::getPrice() {
    return price;
}

int main()
{
    cout << "=== VR体验管理系统 ===" << endl;
    cout << endl;
    
    VRExperience experiences[3] = {
        VRExperience("过山车", 5, 50),
        VRExperience("射击游戏", 15, 80),
        VRExperience("恐怖密室", 20, 100)
    };
    
    cout << endl;
    cout << "当前体验项目：" << endl;
    int totalPrice = 0;
    for (int i = 0; i < 3; i++) {
        experiences[i].display();
        totalPrice += experiences[i].getPrice();
    }
    
    cout << endl;
    cout << "单次全部体验的总价格：" << totalPrice << "元" << endl;
    cout << endl;

    cout << "新增默认项目：" << endl;
    VRExperience defaultExp;
    defaultExp.display();
    
    cout << endl;
    cout << "程序结束，所有项目将被销毁..." << endl;
    
    return 0;
}