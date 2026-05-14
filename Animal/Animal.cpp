#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string name;

public:
    Animal(string n) : name(n) {}
    
    string getName() const { 
        return name; 
    }
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
public:
    Bat(string n, string fc, string fyc) 
        : Animal(n), Mammal(n, fc), Bird(n, fyc) {}

    void display() {
        cout << "名字：" << getName() << endl;
        cout << "毛发颜色：" << fur_color << endl;
        cout << "羽毛颜色：" << feather_color << endl;
    }
};

int main()
{
    Bat bat("小蝠", "棕色", "黑色");
    
    cout << "\n直接访问\n name: " << bat.getName() << endl << endl;
    bat.display();

    return 0;
}