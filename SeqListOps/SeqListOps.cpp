#include <iostream>
using namespace std;

const int MaxSize = 100;
template <typename DataType>
class SeqList
{
public:
    SeqList();                                  // 默认构造，初始化空表
    SeqList(DataType a[], int n);               // 批量数组初始化
    void Insert(int i, DataType x);             // 在第i个位序插入x
    DataType Delete(int i);                     // 删除第i个位序元素，返回被删的值
    int Locate(DataType x);                     // 按值查找，返回位序，找不到返回0
    void PrintList();                           // 遍历输出顺序表
private:
    DataType data[MaxSize];
    int length;
};

// 默认构造函数
template <typename DataType>
SeqList<DataType>::SeqList()
{
    length = 0;
}

// 批量构造函数
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

// 位序i处插入元素x，i从1开始
template <typename DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
    if (length >= MaxSize)
    {
        cout << "顺序表已满，无法插入！" << endl;
        return;
    }
    if (i < 1 || i > length + 1)
    {
        cout << "插入位置非法！" << endl;
        return;
    }
    // 元素后移
    for (int j = length; j >= i; j--)
    {
        data[j] = data[j - 1];
    }
    data[i - 1] = x;
    length++;
}

// 删除位序i的元素，返回被删除的值
template <typename DataType>
DataType SeqList<DataType>::Delete(int i)
{
    DataType val;
    if (i < 1 || i > length)
    {
        cout << "删除位置非法！" << endl;
        return -1;
    }
    val = data[i - 1];
    // 元素前移
    for (int j = i; j < length; j++)
    {
        data[j - 1] = data[j];
    }
    length--;
    return val;
}

// 按值查找，返回位序；不存在返回0
template <typename DataType>
int SeqList<DataType>::Locate(DataType x)
{
    for (int i = 0; i < length; i++)
    {
        if (data[i] == x)
        {
            return i + 1;
        }
    }
    return 0;
}

// 遍历打印
template <typename DataType>
void SeqList<DataType>::PrintList()
{
    cout << "顺序表：";
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    // 初始7个元素
    int arr[] = { 10, 20, 30, 40, 50, 60, 70 };
    int n = sizeof(arr) / sizeof(arr[0]);
    SeqList<int> L(arr, n);

    cout << "【初始顺序表】" << endl;
    L.PrintList();

    // 在第3个位序插入99
    cout << "\n【在位序3插入元素99】" << endl;
    L.Insert(3, 99);
    L.PrintList();

    // 删除第5个位序元素
    cout << "\n【删除位序5的元素】" << endl;
    int delVal = L.Delete(5);
    cout << "被删除元素：" << delVal << endl;
    L.PrintList();

    // 按值查找元素60
    cout << "\n【查找元素60】" << endl;
    int pos = L.Locate(60);
    if (pos != 0)
        cout << "元素60的位序是：" << pos << endl;
    else
        cout << "未找到该元素" << endl;

    return 0;
}