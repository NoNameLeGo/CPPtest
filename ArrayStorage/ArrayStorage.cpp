#include <iostream>

using namespace std;

int main()
{
    int r[5];

    r[0] = 10;
    r[1] = 20;
    r[2] = 30;
    r[3] = 40;
    r[4] = 50;

    for (int i = 0; i < 5; i++) {
        cout << "r[" << i << "] = " << r[i] << endl;
    }

    return 0;
}