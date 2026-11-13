#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyList {
private:
    Node* head;

public:
    DoublyList() {
        head = new Node;
        head->data = 0;
        head->prev = NULL;
        head->next = NULL;
    }

    // 尾插法
    void append(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        Node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
        newNode->prev = p;
    }

    // 按位置查找，返回结点地址
    Node* findByPos(int pos) {
        if (pos < 1) {
            return NULL;
        }

        Node* p = head->next;
        int i = 1;
        while (p != NULL && i < pos) {
            p = p->next;
            i++;
        }
        return p;
    }

    // 按值查找，返回结点地址
    Node* findByValue(int value) {
        Node* p = head->next;
        while (p != NULL) {
            if (p->data == value) {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }

    // 按位置删除
    void removeAt(int pos) {
        Node* p = findByPos(pos);
        if (p == NULL) {
            cout << "删除位置不合法" << endl;
            return;
        }

        p->prev->next = p->next;
        if (p->next != NULL) {
            p->next->prev = p->prev;
        }
        delete p;
    }

    // 修改第 pos 个结点的数据
    void modifyAt(int pos, int value) {
        Node* p = findByPos(pos);
        if (p == NULL) {
            cout << "修改位置不合法" << endl;
            return;
        }
        p->data = value;
    }

    void showForward() {
        if (head->next == NULL) {
            cout << "链表为空" << endl;
            return;
        }
        Node* p = head->next;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 释放所有结点
    ~DoublyList() {
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
    DoublyList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    cout << "初始链表：";
    list.showForward();

    Node* p1 = list.findByValue(30);
    if (p1 != NULL) {
        cout << "按值查找30：找到了" << endl;
    }
    else {
        cout << "按值查找30：没找到" << endl;
    }

    Node* p2 = list.findByPos(2);
    if (p2 != NULL) {
        cout << "按位置查找第2个结点，数据是：" << p2->data << endl;
    }

    list.removeAt(3);
    cout << "删除第3个结点后：";
    list.showForward();

    list.modifyAt(2, 99);
    cout << "把第2个结点的数据改成99后：";
    list.showForward();

    return 0;
}