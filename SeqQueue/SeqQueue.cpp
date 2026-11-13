#include <iostream>

using namespace std;

const int MAX = 6;

class SeqQueue {
private:
    int data[MAX];
    int front;
    int rear;

public:
    SeqQueue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool enQueue(int value) {
        if (isFull()) {
            cout << "队列满，上溢，入队失败：" << value << endl;
            return false;
        }
        data[rear] = value;
        cout << "入队：" << value << "，rear = " << rear << " -> " << (rear + 1) % MAX << endl;
        rear = (rear + 1) % MAX;
        return true;
    }

    bool deQueue(int& value) {
        if (isEmpty()) {
            cout << "队列空，下溢，出队失败" << endl;
            return false;
        }
        value = data[front];
        front = (front + 1) % MAX;
        return true;
    }

    bool getFront(int& value) {
        if (isEmpty()) {
            cout << "队列空，取队头失败" << endl;
            return false;
        }
        value = data[front];
        return true;
    }

    void printQueue() {
        cout << "当前队列：";
        if (isEmpty()) {
            cout << "空" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << data[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main()
{
    SeqQueue q;
    int value;

    cout << "===== 循环顺序队列基础操作 =====" << endl;

    cout << "【初始化】" << endl;
    if (q.isEmpty()) {
        cout << "空队列，front = 0，rear = 0" << endl;
    }

    cout << "【入队】" << endl;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);

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
    if (q.deQueue(value)) {
        cout << "出队：" << value << endl;
    }

    cout << "【再次入队，验证循环】" << endl;
    q.enQueue(60);
    q.enQueue(70);

    cout << "【打印队列】" << endl;
    q.printQueue();

    cout << "【清空队列】" << endl;
    while (q.deQueue(value)) {
        cout << "出队：" << value << endl;
    }

    cout << "【判空】" << endl;
    if (q.isEmpty()) {
        cout << "队列为空，front == rear" << endl;
    }

    cout << "【再出队一次】" << endl;
    q.deQueue(value);

    return 0;
}

