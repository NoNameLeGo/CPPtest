#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    string name;

    Animal(string n) : name(n) {}
};

class Mammal : virtual public Animal {
protected:
    string fur_color;

public:
    Mammal(string n, string fc) : Animal(n), fur_color(fc) {}
};

class Bird : virtual public Animal {
protected:
    string feather_color;

public:
    Bird(string n, string fyc) : Animal(n), feather_color(fyc) {}
};

class Bat : public Mammal, public Bird {
private:
    string wing_type;

public:
    Bat(string n, string fc, string fyc, string wt) 
        : Animal(n), Mammal(n, fc), Bird(n, fyc), wing_type(wt) {}

    void display() {
        cout << "名字：" << name << endl;
        cout << "毛发颜色：" << fur_color << endl;
        cout << "羽毛颜色：" << feather_color << endl;
        cout << "翅膀类型：" << wing_type << endl;
    }
};

int main()
{
    Bat bat("小蝙蝠", "棕色", "灰色", "膜翼");
    
    cout << "\n直接访问 name: " << bat.name << endl;
    bat.display();

    return 0;
}