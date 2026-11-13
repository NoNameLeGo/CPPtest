#include <iostream>

using namespace std;

// ---------- 单向循环链表 ----------
class Node {
public:
    int data;
    Node* next;
};

class CircularList {
private:
    Node* head;

public:
    CircularList() {
        head = new Node;
        head->data = 0;
        head->next = head;
    }

    // 尾插法：把新结点接到尾结点后面
    void append(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;

        Node* p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = newNode;
    }

    void insertAt(int pos, int value) {
        if (pos < 1) {
            cout << "插入位置不合法" << endl;
            return;
        }

        Node* p = head;
        int i = 0;
        while (i < pos - 1 && p->next != head) {
            p = p->next;
            i++;
        }
        if (i < pos - 1) {
            cout << "插入位置不合法" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = p->next;
        p->next = newNode;
    }

    void removeAt(int pos) {
        if (pos < 1) {
            cout << "删除位置不合法" << endl;
            return;
        }

        Node* prev = head;
        Node* p = head->next;
        int i = 1;
        while (p != head && i < pos) {
            prev = p;
            p = p->next;
            i++;
        }
        if (p == head) {
            cout << "删除位置不合法" << endl;
            return;
        }

        prev->next = p->next;
        delete p;
    }

    void show() {
        if (head->next == head) {
            cout << "单向循环链表为空" << endl;
            return;
        }

        Node* p = head->next;
        while (p != head) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 释放所有结点
    ~CircularList() {
        Node* p = head->next;
        while (p != head) {
            Node* temp = p->next;
            delete p;
            p = temp;
        }
        delete head;
    }
};

// ---------- 双向循环链表 ----------
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyCircularList {
private:
    DNode* head;

public:
    DoublyCircularList() {
        head = new DNode;
        head->data = 0;
        head->prev = head;
        head->next = head;
    }

    // 尾插法：新结点插到头结点前面，即链表末尾
    void append(int value) {
        DNode* newNode = new DNode;
        newNode->data = value;
        newNode->next = head;
        newNode->prev = head->prev;

        head->prev->next = newNode;
        head->prev = newNode;
    }

    void insertAt(int pos, int value) {
        if (pos < 1) {
            cout << "插入位置不合法" << endl;
            return;
        }

        DNode* p = head;
        int i = 0;
        while (i < pos - 1 && p->next != head) {
            p = p->next;
            i++;
        }
        if (i < pos - 1) {
            cout << "插入位置不合法" << endl;
            return;
        }

        DNode* newNode = new DNode;
        newNode->data = value;
        newNode->next = p->next;
        newNode->prev = p;
        p->next->prev = newNode;
        p->next = newNode;
    }

    void removeAt(int pos) {
        if (pos < 1) {
            cout << "删除位置不合法" << endl;
            return;
        }

        DNode* p = head->next;
        int i = 1;
        while (p != head && i < pos) {
            p = p->next;
            i++;
        }
        if (p == head) {
            cout << "删除位置不合法" << endl;
            return;
        }

        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }

    void showForward() {
        if (head->next == head) {
            cout << "双向循环链表为空" << endl;
            return;
        }

        DNode* p = head->next;
        while (p != head) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void showBackward() {
        if (head->next == head) {
            cout << "双向循环链表为空" << endl;
            return;
        }

        DNode* p = head->prev;
        while (p != head) {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }

    // 释放所有结点
    ~DoublyCircularList() {
        DNode* p = head->next;
        while (p != head) {
            DNode* temp = p->next;
            delete p;
            p = temp;
        }
        delete head;
    }
};

int main()
{
    cout << "===== 单向循环链表 =====" << endl;
    CircularList c1;
    c1.append(1);
    c1.append(2);
    c1.append(3);
    cout << "初始链表：";
    c1.show();

    c1.insertAt(2, 9);
    cout << "在第2个位置插入9后：";
    c1.show();

    c1.removeAt(1);
    cout << "删除第1个结点后：";
    c1.show();

    cout << endl;
    cout << "===== 双向循环链表 =====" << endl;
    DoublyCircularList c2;
    c2.append(10);
    c2.append(20);
    c2.append(30);
    cout << "正向遍历：";
    c2.showForward();
    cout << "逆向遍历：";
    c2.showBackward();

    c2.insertAt(2, 15);
    cout << "在第2个位置插入15后，正向遍历：";
    c2.showForward();

    c2.removeAt(4);
    cout << "删除第4个结点后，正向遍历：";
    c2.showForward();

    return 0;
}