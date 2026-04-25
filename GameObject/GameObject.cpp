#include <iostream>
#include <string>
using namespace std;

class GameObject {
protected:
    string name;
    float x, y, z;

public:
    GameObject(string n, float x0, float y0, float z0) : name(n), x(x0), y(y0), z(z0) {}
    void showInfo() {
        cout << "名称: " << name << ", 坐标: (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

class Player : public GameObject {
private:
    int health;

public:
    Player(string n, float x0, float y0, float z0, int h) : GameObject(n, x0, y0, z0), health(h) {}
    void showInfo() {
        cout << "玩家名称: " << name << ", 坐标: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "生命值: " << health << endl;
    }
    void attack() {
        cout << "玩家 [" << name << "] 发动了攻击！" << endl;
    }
};

int main()
{
    Player player("勇者", 10.5, 20, 5, 100);
    player.showInfo();
    player.attack();
    
    return 0;
}