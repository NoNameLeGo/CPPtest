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

    // 在第 pos 个位置插入（pos 从 1 开始）
    void insertAt(int pos, int value) {
        if (pos < 1) {
            cout << "插入位置不合法" << endl;
            return;
        }

        Node* p = head;
        int i = 1;
        while (i < pos && p != NULL) {
            p = p->next;
            i++;
        }
        if (p == NULL) {
            cout << "插入位置不合法" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        newNode->next = p->next;
        newNode->prev = p;
        if (p->next != NULL) {
            p->next->prev = newNode;
        }
        p->next = newNode;
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

    void showBackward() {
        if (head->next == NULL) {
            cout << "链表为空" << endl;
            return;
        }

        Node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }

        while (p != head) {
            cout << p->data << " ";
            p = p->prev;
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

    cout << "正向遍历：";
    list.showForward();

    cout << "逆向遍历：";
    list.showBackward();

    list.insertAt(2, 15);
    cout << "在第2个位置插入15后，正向遍历：";
    list.showForward();

    cout << "在第2个位置插入15后，逆向遍历：";
    list.showBackward();

    return 0;
}