#include <iostream>
#include <cmath>
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
    void ParentChild(int i);
    void CountDegree(int &n0, int &n1, int &n2);
    int GetDepth();
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

void SeqBiTree::ParentChild(int i) {
    cout << "===== 查询编号 " << i << " 的结点关系 =====" << endl;
    if (biTreeNum == 0) {
        cout << "空树，无法查询" << endl;
        return;
    }
    if (i < 1 || i > biTreeNum) {
        cout << "编号越界！有效范围 1 ~ " << biTreeNum << endl;
        return;
    }
    if (data[i] == '#') {
        cout << "该位置是空位（#），没有结点" << endl;
        return;
    }
    cout << "该结点数据：" << data[i] << endl;
    if (i == 1) {
        cout << "双亲：根结点无双亲" << endl;
    } else {
        int parentIdx = i / 2;
        if (data[parentIdx] != '#') {
            cout << "双亲：下标 " << parentIdx << "，数据 " << data[parentIdx] << endl;
        } else {
            cout << "双亲：下标 " << parentIdx << "，无该结点（空位#）" << endl;
        }
    }
    int leftIdx = 2 * i;
    if (leftIdx > biTreeNum || data[leftIdx] == '#') {
        cout << "左孩子：无" << endl;
    } else {
        cout << "左孩子：下标 " << leftIdx << "，数据 " << data[leftIdx] << endl;
    }
    int rightIdx = 2 * i + 1;
    if (rightIdx > biTreeNum || data[rightIdx] == '#') {
        cout << "右孩子：无" << endl;
    } else {
        cout << "右孩子：下标 " << rightIdx << "，数据 " << data[rightIdx] << endl;
    }
}

void SeqBiTree::CountDegree(int &n0, int &n1, int &n2) {
    n0 = 0; n1 = 0; n2 = 0;
    if (biTreeNum == 0) return;
    for (int i = 1; i <= biTreeNum; i++) {
        if (data[i] == '#') continue;
        int children = 0;
        if (2 * i <= biTreeNum && data[2 * i] != '#') children++;
        if (2 * i + 1 <= biTreeNum && data[2 * i + 1] != '#') children++;
        if (children == 0) n0++;
        else if (children == 1) n1++;
        else n2++;
    }
}

int SeqBiTree::GetDepth() {
    if (biTreeNum == 0) return 0;
    int depth = 0;
    int n = biTreeNum;
    while (n > 0) {
        depth++;
        n = n / 2;
    }
    return depth;
}

int main()
{
    system("chcp 65001 >nul");
    cout << "===== 任务2：顺序存储二叉树的结点关系查询与性质验证 =====" << endl;

    SeqBiTree t;
    cout << endl << "--- 主测试 ---" << endl;
    t.CreateBiTree();
    t.LevelOrder();

    int n0, n1, n2;
    t.CountDegree(n0, n1, n2);
    cout << "叶子结点数 n0=" << n0;
    cout << "，度1结点数 n1=" << n1;
    cout << "，度2结点数 n2=" << n2 << endl;
    cout << "验证性质3 n0==n2+1：";
    if (n0 == n2 + 1) {
        cout << "成立" << endl;
    } else {
        cout << "不成立" << endl;
    }
    cout << "完全二叉树深度：" << t.GetDepth() << endl;
    t.ParentChild(2);

    cout << endl << "--- 边界测试：空树 ---" << endl;
    SeqBiTree emptyTree;
    emptyTree.CreateBiTree();
    int en0, en1, en2;
    emptyTree.CountDegree(en0, en1, en2);
    cout << "n0=" << en0 << " n1=" << en1 << " n2=" << en2 << endl;
    cout << "深度=" << emptyTree.GetDepth() << endl;
    emptyTree.ParentChild(1);

    cout << endl << "--- 边界测试：编号越界 ---" << endl;
    t.ParentChild(99);

    return 0;
}
