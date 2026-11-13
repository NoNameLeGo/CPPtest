#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedQueue() {
        Node* head = new Node;
        head->next = NULL;
        front = head;
        rear = head;
    }

    bool isEmpty() {
        return front == rear;
    }

    void enQueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        rear->next = newNode;
        rear = newNode;
    }

    bool deQueue(int& value) {
        if (isEmpty()) {
            return false;
        }
        Node* p = front->next;
        value = p->data;
        front->next = p->next;
        if (rear == p) {
            rear = front;
        }
        delete p;
        return true;
    }

    ~LinkedQueue() {
        Node* p = front;
        while (p != NULL) {
            Node* temp = p->next;
            delete p;
            p = temp;
        }
    }
};

int main()
{
    LinkedQueue boys;
    LinkedQueue girls;
    int boy, girl;
    int count = 0;

    for (int i = 1; i <= 5; i++) {
        boys.enQueue(i);
    }
    for (int i = 1; i <= 3; i++) {
        girls.enQueue(i);
    }

    cout << "===== 舞伴配对 =====" << endl;
    cout << "男生 5 人，女生 3 人，按到场顺序排队" << endl;

    cout << endl << "【配对过程】" << endl;
    while (!boys.isEmpty() && !girls.isEmpty()) {
        boys.deQueue(boy);
        girls.deQueue(girl);
        count++;
        cout << "第 " << count << " 对：男" << boy << " - 女" << girl << endl;
    }

    cout << endl << "【剩余未配对】" << endl;
    if (boys.isEmpty() && girls.isEmpty()) {
        cout << "全部配对完成" << endl;
    }
    while (!boys.isEmpty()) {
        boys.deQueue(boy);
        cout << "男" << boy << " 继续等待" << endl;
    }
    while (!girls.isEmpty()) {
        girls.deQueue(girl);
        cout << "女" << girl << " 继续等待" << endl;
    }

    return 0;
}
