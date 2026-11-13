#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "请输入分子和分母：";
    cin >> a >> b;

    // 辗转相除法求最大公约数
    int x = a, y = b;
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }

    cout << "化简结果：" << a / x << "/" << b / x << endl;

    return 0;
}