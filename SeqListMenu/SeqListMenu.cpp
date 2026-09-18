#include <iostream>
using namespace std;

const int MaxSize = 100;
template <typename DataType>
class SeqList
{
public:
    SeqList();
    SeqList(DataType a[], int n);
    void Insert(int i, DataType x);
    DataType Delete(int i);
    int Locate(DataType x);
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
    for (int j = length; j >= i; j--)
    {
        data[j] = data[j - 1];
    }
    data[i - 1] = x;
    length++;
}

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
    for (int j = i; j < length; j++)
    {
        data[j - 1] = data[j];
    }
    length--;
    return val;
}

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

template <typename DataType>
void SeqList<DataType>::PrintList()
{
    cout << "当前顺序表：";
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void ShowMenu()
{
    cout << "\n=====顺序表操作菜单=====" << endl;
    cout << "1. 插入元素" << endl;
    cout << "2. 删除元素" << endl;
    cout << "3. 按值查找元素" << endl;
    cout << "0. 退出程序" << endl;
    cout << "请输入你的选择：";
}

int main()
{
    int arr[] = { 1, 3, 5, 7, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    SeqList<int> L(arr, n);

    cout << "初始线性表已创建！" << endl;
    L.PrintList();

    int op;
    while (true)
    {
        ShowMenu();
        cin >> op;
        if (op == 0)
        {
            cout << "程序结束！" << endl;
            break;
        }
        else if (op == 1)
        {
            int pos, val;
            cout << "请输入插入位序、插入的值：";
            cin >> pos >> val;
            L.Insert(pos, val);
            L.PrintList();
        }
        else if (op == 2)
        {
            int pos;
            cout << "请输入要删除元素的位序：";
            cin >> pos;
            int del = L.Delete(pos);
            if (del != -1)
                cout << "被删除元素：" << del << endl;
            L.PrintList();
        }
        else if (op == 3)
        {
            int val;
            cout << "请输入要查找的值：";
            cin >> val;
            int res = L.Locate(val);
            if (res != 0)
                cout << "元素" << val << "的位序为：" << res << endl;
            else
                cout << "未找到该元素！" << endl;
            L.PrintList();
        }
        else
        {
            cout << "输入选项错误，请重新选择！" << endl;
        }
    }
    return 0;
}