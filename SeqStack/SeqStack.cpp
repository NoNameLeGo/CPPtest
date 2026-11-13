#include <iostream>

using namespace std;

const int MAX = 5;

class SeqStack {
private:
    int data[MAX];
    int top;

public:
    SeqStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "栈满，上溢，入栈失败：" << value << endl;
            return;
        }
        top++;
        data[top] = value;
        cout << "入栈：" << value << "，当前 top = " << top << endl;
    }

    bool pop(int& value) {
        if (isEmpty()) {
            cout << "栈空，下溢，出栈失败" << endl;
            return false;
        }
        value = data[top];
        top--;
        return true;
    }

    bool getTop(int& value) {
        if (isEmpty()) {
            cout << "栈空，取栈顶失败" << endl;
            return false;
        }
        value = data[top];
        return true;
    }
};

int main()
{
    SeqStack s;
    int value;

    cout << "===== 顺序栈基础操作 =====" << endl;

    cout << endl << "【初始化】" << endl;
    if (s.isEmpty()) {
        cout << "空栈，top = -1" << endl;
    }

    cout << endl << "【入栈】" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

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
        cout << "栈为空" << endl;
    }
    else {
        cout << "栈不为空" << endl;
    }

    cout << endl << "【清空栈】" << endl;
    while (s.pop(value)) {
        cout << "出栈：" << value << endl;
    }

    cout << endl << "【判空】" << endl;
    if (s.isEmpty()) {
        cout << "栈为空，top = -1" << endl;
    }

    cout << endl << "【再出栈一次】" << endl;
    s.pop(value);

    return 0;
}