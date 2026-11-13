#include <iostream>
#include <string>

using namespace std;

class VRNode {
public:
    int id;
    string name;
    string type;
    float x, y, z;
    VRNode* next;

    VRNode(int i, string n, string t, float x0, float y0, float z0) {
        id = i;
        name = n;
        type = t;
        x = x0;
        y = y0;
        z = z0;
        next = NULL;
    }
};

class VRSceneList {
private:
    VRNode* head;

public:
    VRSceneList() {
        head = new VRNode(0, "", "", 0, 0, 0);
    }

    // 尾插法：把新物体接到链表末尾
    void append(int id, string name, string type, float x, float y, float z) {
        VRNode* newNode = new VRNode(id, name, type, x, y, z);

        VRNode* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }

    void showAll() {
        if (head->next == NULL) {
            cout << "当前VR场景没有任何资源，场景为空。" << endl;
            return;
        }

        cout << "===== VR场景资源清单 =====" << endl;
        VRNode* p = head->next;
        int index = 1;
        while (p != NULL) {
            cout << "资源序号：" << index << endl;
            cout << "  物体ID：" << p->id << endl;
            cout << "  物体名称：" << p->name << endl;
            cout << "  资源类型：" << p->type << endl;
            cout << "  场景坐标：(" << p->x << ", " << p->y << ", " << p->z << ")" << endl;
            cout << "-------------------------" << endl;
            p = p->next;
            index++;
        }
    }

    // 释放所有节点
    ~VRSceneList() {
        VRNode* p = head;
        while (p != NULL) {
            VRNode* temp = p->next;
            delete p;
            p = temp;
        }
    }
};

int main()
{
    VRSceneList scene;

    scene.append(101, "地面", "地面", 0, 0, 0);
    scene.append(102, "主墙体", "墙体", 0, 0, -5);
    scene.append(103, "石凳", "静态摆件", 3, 0, 2);
    scene.append(104, "暖光吊灯", "氛围光源", 0, 3, 0);

    scene.showAll();

    return 0;
}