#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    float arr[6] = {1.5, 2.8, 3.2, 4.9, 5.1, 6.3};

    ofstream fout("data.txt");
    for (int i = 0; i < 6; i++) {
        fout << arr[i] << endl;
    }
    fout.close();

    ifstream fin("data.txt");
    float sum = 0;
    float val;
    for (int i = 0; i < 6; i++) {
        fin >> val;
        sum += val;
    }
    fin.close();

    float avg = sum / 6;
    cout << "总和：" << sum << endl;
    cout << "平均值：" << avg << endl;

    return 0;
}