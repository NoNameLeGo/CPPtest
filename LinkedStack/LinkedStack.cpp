#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedStack {
private:
    Node* top;

public:
    LinkedStack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "入栈：" << value << endl;
    }

    bool pop(int& value) {
        if (isEmpty()) {
            cout << "链栈为空，出栈失败" << endl;
            return false;
        }
        Node* p = top;
        value = p->data;
        top = p->next;
        delete p;
        return true;
    }

    bool getTop(int& value) {
        if (isEmpty()) {
            cout << "链栈为空，取栈顶失败" << endl;
            return false;
        }
        value = top->data;
        return true;
    }

    ~LinkedStack() {
        Node* p = top;
        while (p != NULL) {
            Node* temp = p->next;
            delete p;
            p = temp;
        }
    }
};

int main()
{
    LinkedStack s;
    int value;

    cout << "===== 链栈基础操作 =====" << endl;

    cout << endl << "【初始化】" << endl;
    if (s.isEmpty()) {
        cout << "链栈为空，top = NULL" << endl;
    }

    cout << endl << "【入栈】" << endl;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << endl << "【取栈顶】" << endl;
    if (s.getTop(value)) {
        cout << "当前栈顶元素：" << value << endl;
    }

    cout << endl << "【出栈】" << endl;
    if (s.pop(value)) {
        cout << "出栈：" << value << endl;
    }

    cout << endl << "【取栈顶】" << endl;
    if (s.getTop(value)) {
        cout << "当前栈顶元素：" << value << endl;
    }

    cout << endl << "【判空】" << endl;
    if (s.isEmpty()) {
        cout << "链栈为空" << endl;
    }
    else {
        cout << "链栈不为空" << endl;
    }

    cout << endl << "【清空链栈】" << endl;
    while (s.pop(value)) {
        cout << "出栈：" << value << endl;
    }

    cout << endl << "【判空】" << endl;
    if (s.isEmpty()) {
        cout << "链栈为空，top = NULL" << endl;
    }

    cout << endl << "【再出栈一次】" << endl;
    s.pop(value);

    return 0;
}