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
        cout << "入队：" << value << endl;
    }

    bool deQueue(int& value) {
        if (isEmpty()) {
            cout << "队列空，下溢，出队失败" << endl;
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

    bool getFront(int& value) {
        if (isEmpty()) {
            cout << "队列空，取队头失败" << endl;
            return false;
        }
        value = front->next->data;
        return true;
    }

    void printQueue() {
        cout << "当前队列：";
        Node* p = front->next;
        if (p == NULL) {
            cout << "空" << endl;
            return;
        }
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
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
    LinkedQueue q;
    int value;

    cout << "===== 链队列基础操作 =====" << endl;

    cout << "【初始化】" << endl;
    if (q.isEmpty()) {
        cout << "空队列，front 和 rear 都指向头结点" << endl;
    }

    cout << "【入队】" << endl;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);

    cout << "【打印队列】" << endl;
    q.printQueue();

    cout << "【取队头】" << endl;
    if (q.getFront(value)) {
        cout << "队头元素：" << value << endl;
    }

    cout << "【出队】" << endl;
    if (q.deQueue(value)) {
        cout << "出队：" << value << endl;
    }

    cout << "【取队头】" << endl;
    if (q.getFront(value)) {
        cout << "队头元素：" << value << endl;
    }

    cout << "【判空】" << endl;
    if (q.isEmpty()) {
        cout << "队列为空" << endl;
    }
    else {
        cout << "队列不为空" << endl;
    }

    cout << "【清空队列】" << endl;
    while (q.deQueue(value)) {
        cout << "出队：" << value << endl;
    }

    cout << "【判空】" << endl;
    if (q.isEmpty()) {
        cout << "队列为空，front 和 rear 重新指向头结点" << endl;
    }

    cout << "【再出队一次】" << endl;
    q.deQueue(value);

    return 0;
}

