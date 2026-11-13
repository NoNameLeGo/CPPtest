#include <iostream>
using namespace std;

const int MaxSize = 100;
template <typename DataType>
class SeqList
{
public:
    SeqList();
    SeqList(DataType a[], int n);
    void PrintList();
private:
    DataType data[MaxSize];
    int length;
};

template <typename DataType>
SeqList<DataType>::SeqList()
{
    length = 0;
}

template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n)
{
    if (n > MaxSize)
    {
        n = MaxSize;
    }
    for (int i = 0; i < n; i++)
    {
        data[i] = a[i];
    }
    length = n;
}

template <typename DataType>
void SeqList<DataType>::PrintList()
{
    cout << "顺序表有效元素：";
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60, 70 };
    int n = sizeof(arr) / sizeof(arr[0]);

    SeqList<int> L(arr, n);
    L.PrintList();
    return 0;
}