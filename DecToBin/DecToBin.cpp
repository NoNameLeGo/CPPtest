#include <iostream>

using namespace std;

const int MAX = 100;

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

    void push(int value) {
        top++;
        data[top] = value;
    }

    int pop() {
        int value = data[top];
        top--;
        return value;
    }
};

int main()
{
    int n;
    cout << "请输入一个非负十进制整数：";
    cin >> n;

    if (n == 0) {
        cout << "0 的二进制是：0" << endl;
        return 0;
    }

    SeqStack s;
    int temp = n;

    cout << endl << "【除 2 取余，余数入栈】" << endl;
    while (temp > 0) {
        int r = temp % 2;
        s.push(r);
        cout << temp << " / 2 = " << temp / 2 << " 余 " << r << "，余数 " << r << " 入栈" << endl;
        temp = temp / 2;
    }

    cout << endl << "【逆序出栈，得到二进制】" << endl;
    cout << n << " 的二进制是：";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}