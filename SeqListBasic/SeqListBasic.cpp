#include <iostream>
using namespace std;

const int MaxSize = 100;
template <typename DataType>
class SeqList
{
public:
    SeqList();                          // 默认构造，初始化空表
    SeqList(DataType a[], int n);       // 批量数组初始化
    void PrintList();                   // 遍历输出顺序表
private:
    DataType data[MaxSize];
    int length;
};

// 默认构造函数：初始化顺序表
template <typename DataType>
SeqList<DataType>::SeqList()
{
    length = 0;
}

// 批量构造函数：将数组a中n个元素存入顺序表
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

// 遍历打印所有有效元素
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
    // 共7个整数（满足6~8个要求）
    int arr[] = { 10, 20, 30, 40, 50, 60, 70 };
    int n = sizeof(arr) / sizeof(arr[0]);

    SeqList<int> L(arr, n);
    L.PrintList();
    return 0;
}