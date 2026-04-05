#include <iostream>
#include <string>
using namespace std;

class VRHeadset {
private:
    string brand;
    int width;
    int rate;

public:
    VRHeadset() : brand("DefaultVR"), width(3840), rate(90) {}
    VRHeadset(string b, int w, int r) : brand(b), width(w), rate(r) {}
    VRHeadset(string b) : brand(b), width(4000), rate(120) {}
    ~VRHeadset();
    void showInfo();
};

VRHeadset::~VRHeadset() {
    cout << brand << " 头盔对象已销毁" << endl;
}

void VRHeadset::showInfo() {
    cout << "品牌: " << brand << endl;
    cout << "分辨率宽度: " << width << endl;
    cout << "刷新率: " << rate << "Hz" << endl;
}

int main()
{
    cout << "无参构造函数调用" << endl;
    VRHeadset h1;
    h1.showInfo();
    cout << "-----------------" << endl;

    cout << "带参构造函数调用" << endl;
    VRHeadset h2("Pico 4", 4000, 120);
    h2.showInfo();
    cout << "-----------------" << endl;

    cout << "带默认参数的构造函数调用" << endl;
    VRHeadset h3("Meta Quest 3");
    h3.showInfo();
    cout << "-----------------" << endl;

    return 0;
}
