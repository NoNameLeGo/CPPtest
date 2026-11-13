#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "请输入n：";
    cin >> n;

    int sum1 = 0;
    for (int i = 1; i <= n; i++) {
        sum1 += i;
    }
    cout << "迭代版本：1+2+...+" << n << " = " << sum1 << endl;

    int sum2 = n * (n + 1) / 2;
    cout << "公式版本：" << sum2 << endl;

    return 0;
}