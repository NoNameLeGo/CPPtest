#include <iostream>

using namespace std;

int getMax(int r[], int n) {
    int max = r[0];
    for (int i = 1; i < n; i++) {
        if (r[i] > max) {
            max = r[i];
        }
    }
    return max;
}

int getMin(int r[], int n) {
    int min = r[0];
    for (int i = 1; i < n; i++) {
        if (r[i] < min) {
            min = r[i];
        }
    }
    return min;
}

int main()
{
    int r[6] = {23, 5, 78, 12, 96, 41};
    int n = 6;

    cout << "数组元素：";
    for (int i = 0; i < n; i++) {
        cout << r[i] << " ";
    }
    cout << endl;

    cout << "最大值：" << getMax(r, n) << endl;
    cout << "最小值：" << getMin(r, n) << endl;

    return 0;
}