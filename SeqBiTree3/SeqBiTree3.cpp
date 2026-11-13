#include <iostream>
#include <cstdlib>

using namespace std;

const int MaxSize = 20;

class SeqBiTree {
private:
    char data[MaxSize];
    int biTreeNum;

    void PreOrder(int i);
    void InOrder(int i);
    void PostOrder(int i);

public:
    SeqBiTree();
    void CreateBiTree();
    void PreOrder();
    void InOrder();
    void PostOrder();
};

SeqBiTree::SeqBiTree() {
    biTreeNum = 0;
    for (int i = 1; i < MaxSize; i++) {
        data[i] = '#';
    }
}

void SeqBiTree::CreateBiTree() {
    cout << "请输入结点个数：";
    cin >> biTreeNum;
    if (biTreeNum == 0) {
        cout << "空树建立完成" << endl;
        return;
    }
    for (int i = 1; i <= biTreeNum; i++) {
        cout << "请输入 data[" << i << "]（空位输入 #）：";
        cin >> data[i];
    }
    cout << "二叉树建立完成" << endl;
}

void SeqBiTree::PreOrder(int i) {
    if (i > biTreeNum || data[i] == '#') return;
    cout << data[i] << " ";
    PreOrder(2 * i);
    PreOrder(2 * i + 1);
}

void SeqBiTree::InOrder(int i) {
    if (i > biTreeNum || data[i] == '#') return;
    InOrder(2 * i);
    cout << data[i] << " ";
    InOrder(2 * i + 1);
}

void SeqBiTree::PostOrder(int i) {
    if (i > biTreeNum || data[i] == '#') return;
    PostOrder(2 * i);
    PostOrder(2 * i + 1);
    cout << data[i] << " ";
}

void SeqBiTree::PreOrder() {
    cout << "先序遍历结果：";
    PreOrder(1);
    cout << endl;
}

void SeqBiTree::InOrder() {
    cout << "中序遍历结果：";
    InOrder(1);
    cout << endl;
}

void SeqBiTree::PostOrder() {
    cout << "后序遍历结果：";
    PostOrder(1);
    cout << endl;
}

int main()
{
    system("chcp 65001 >nul");
    cout << "===== 任务3：顺序存储二叉树的递归遍历 =====" << endl;

    SeqBiTree t;
    cout << endl << "--- 主测试 ---" << endl;
    t.CreateBiTree();
    t.PreOrder();
    t.InOrder();
    t.PostOrder();

    cout << endl << "--- 边界测试：空树 ---" << endl;
    SeqBiTree emptyTree;
    emptyTree.CreateBiTree();
    emptyTree.PreOrder();
    emptyTree.InOrder();
    emptyTree.PostOrder();

    cout << endl << "--- 边界测试：单结点 ---" << endl;
    SeqBiTree singleTree;
    singleTree.CreateBiTree();
    singleTree.PreOrder();
    singleTree.InOrder();
    singleTree.PostOrder();

    return 0;
}
