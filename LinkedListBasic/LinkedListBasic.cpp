#include <iostream>

using namespace std;

class Node {
public:
    int id;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = new Node;
        head->id = 0;
        head->next = NULL;
    }

    // 尾插法：把新ID接到链表末尾
    void append(int id) {
        Node* newNode = new Node;
        newNode->id = id;
        newNode->next = NULL;

        Node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }

    void showAll() {
        if (head->next == NULL) {
            cout << "当前场景为空，没有任何已录入的物体资源。" << endl;
            return;
        }

        Node* p = head->next;
        int index = 1;
        while (p != NULL) {
            cout << "第" << index << "个物体 ID：" << p->id << "（已入库）" << endl;
            p = p->next;
            index++;
        }
    }

    // 释放所有节点
    ~LinkedList() {
        Node* p = head;
        while (p != NULL) {
            Node* temp = p->next;
            delete p;
            p = temp;
        }
    }
};

int main()
{
    LinkedList list;

    list.append(101);
    list.append(102);
    list.append(103);
    list.append(104);

    cout << "===== VR场景资源ID清单 =====" << endl;
    list.showAll();

    return 0;
}