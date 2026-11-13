#include <iostream>
#include <cstdlib>

using namespace std;

const int MaxSize = 20;

class SeqBiTree {
private:
    char data[MaxSize];
    int biTreeNum;

public:
    SeqBiTree();
    void CreateBiTree();
    void LevelOrder();
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

void SeqBiTree::LevelOrder() {
    if (biTreeNum == 0) {
        cout << "空树，没有结点" << endl;
        return;
    }
    cout << "层序遍历结果：";
    for (int i = 1; i <= biTreeNum; i++) {
        if (data[i] != '#') {
            cout << data[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    system("chcp 65001 >nul");
    cout << "===== 任务1：二叉树顺序存储建立与层序遍历 =====" << endl;

    SeqBiTree t;
    cout << endl << "--- 主测试 ---" << endl;
    t.CreateBiTree();
    t.LevelOrder();

    cout << endl << "--- 边界测试：空树 ---" << endl;
    SeqBiTree emptyTree;
    emptyTree.CreateBiTree();
    emptyTree.LevelOrder();

    cout << endl << "--- 边界测试：单结点 ---" << endl;
    SeqBiTree singleTree;
    singleTree.CreateBiTree();
    singleTree.LevelOrder();

    return 0;
}
