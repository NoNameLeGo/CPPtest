#include <iostream>
#include <cmath>

using namespace std;

const int MaxSize = 20;

class SeqBiTree {
private:
    char data[MaxSize];
    int biTreeNum;

    // 私有递归版本
    void PreOrder(int i);
    void InOrder(int i);
    void PostOrder(int i);

public:
    SeqBiTree();
    void CreateBiTree();       // 任务1：建立
    void LevelOrder();         // 任务1：层序遍历
    void ParentChild(int i);   // 任务2：求双亲、左孩子、右孩子
    void CountDegree(int &n0, int &n1, int &n2); // 任务2：统计度数
    int GetDepth();            // 任务2：求深度
    void PreOrder();           // 任务3：先序遍历
    void InOrder();            // 任务3：中序遍历
    void PostOrder();          // 任务3：后序遍历
};

// 构造函数：biTreeNum=0，所有位置填空位标记 '#'
SeqBiTree::SeqBiTree() {
    biTreeNum = 0;
    for (int i = 1; i < MaxSize; i++) {
        data[i] = '#';
    }
}

// 任务1：按层序编号顺序建立二叉树
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

// 任务1：层序遍历——按下标从小到大依次输出非空结点
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

// 任务2：根据编号 i 求双亲、左孩子、右孩子
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
    // 双亲
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
    // 左孩子
    int leftIdx = 2 * i;
    if (leftIdx > biTreeNum || data[leftIdx] == '#') {
        cout << "左孩子：无" << endl;
    } else {
        cout << "左孩子：下标 " << leftIdx << "，数据 " << data[leftIdx] << endl;
    }
    // 右孩子
    int rightIdx = 2 * i + 1;
    if (rightIdx > biTreeNum || data[rightIdx] == '#') {
        cout << "右孩子：无" << endl;
    } else {
        cout << "右孩子：下标 " << rightIdx << "，数据 " << data[rightIdx] << endl;
    }
}

// 任务2：统计 n0、n1、n2
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

// 任务2：求完全二叉树深度
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

// 任务3：递归先序遍历（根→左→右）
void SeqBiTree::PreOrder(int i) {
    if (i > biTreeNum || data[i] == '#') return;
    cout << data[i] << " ";
    PreOrder(2 * i);
    PreOrder(2 * i + 1);
}

// 任务3：递归中序遍历（左→根→右）
void SeqBiTree::InOrder(int i) {
    if (i > biTreeNum || data[i] == '#') return;
    InOrder(2 * i);
    cout << data[i] << " ";
    InOrder(2 * i + 1);
}

// 任务3：递归后序遍历（左→右→根）
void SeqBiTree::PostOrder(int i) {
    if (i > biTreeNum || data[i] == '#') return;
    PostOrder(2 * i);
    PostOrder(2 * i + 1);
    cout << data[i] << " ";
}

// 任务3：对外接口——三个无参版本
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
    // ===== 主测试：用完全二叉树 A(B,C,D,E,#,F) 做演示 =====
    // 数组下标：1:A  2:B  3:C  4:D  5:E  6:#  7:F
    cout << "===== 实验八：二叉树顺序结构操作 =====" << endl;

    SeqBiTree t;
    cout << endl << "--- 任务1：建立与层序遍历 ---" << endl;
    t.CreateBiTree();
    t.LevelOrder();

    cout << endl << "--- 任务2：结点关系查询与性质验证 ---" << endl;
    int n0, n1, n2;
    t.CountDegree(n0, n1, n2);
    cout << "叶子结点数 n0=" << n0 << "，度1结点数 n1=" << n1 << "，度2结点数 n2=" << n2 << endl;
    cout << "验证性质3 n0==n2+1：" << (n0 == n2 + 1 ? "成立 ✓" : "不成立 ✗") << endl;
    cout << "完全二叉树深度：" << t.GetDepth() << endl;
    t.ParentChild(2);  // 查询编号2的结点

    cout << endl << "--- 任务3：递归遍历 ---" << endl;
    t.PreOrder();
    t.InOrder();
    t.PostOrder();

    // ===== 边界测试1：空树 =====
    cout << endl << "===== 边界测试1：空树 =====" << endl;
    SeqBiTree emptyTree;
    emptyTree.CreateBiTree();
    emptyTree.LevelOrder();
    emptyTree.PreOrder();
    emptyTree.InOrder();
    emptyTree.PostOrder();

    // ===== 边界测试2：单结点 =====
    cout << endl << "===== 边界测试2：单结点 =====" << endl;
    SeqBiTree singleTree;
    singleTree.CreateBiTree();
    singleTree.LevelOrder();
    singleTree.PreOrder();
    singleTree.InOrder();
    singleTree.PostOrder();
    int sn0, sn1, sn2;
    singleTree.CountDegree(sn0, sn1, sn2);
    cout << "n0=" << sn0 << " n1=" << sn1 << " n2=" << sn2 << endl;
    cout << "深度=" << singleTree.GetDepth() << endl;

    return 0;
}
