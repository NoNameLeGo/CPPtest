#include <iostream>

using namespace std;

const int MAX = 20;

struct TreeNode {
    char data;
    int parent;
};

class ParentTree {
private:
    TreeNode nodes[MAX];
    int n;

public:
    ParentTree() {
        n = 0;
    }

    void create() {
        cin >> n;
        cout << "结点个数：" << n << endl;
        for (int i = 0; i < n; i++) {
            cin >> nodes[i].data >> nodes[i].parent;
            cout << "结点" << i << "：数据 " << nodes[i].data;
            cout << "，双亲下标 " << nodes[i].parent << endl;
        }
    }

    void printTree() {
        cout << "下标  数据  双亲" << endl;
        for (int i = 0; i < n; i++) {
            cout << i << "     " << nodes[i].data;
            cout << "     " << nodes[i].parent << endl;
        }
    }

    void levelOrder() {
        if (n == 0) {
            cout << "空树，没有结点" << endl;
            return;
        }
        int queue[MAX];
        int front = 0;
        int rear = 0;
        for (int i = 0; i < n; i++) {
            if (nodes[i].parent == -1) {
                queue[rear] = i;
                rear++;
            }
        }
        while (front < rear) {
            int cur = queue[front];
            front++;
            cout << nodes[cur].data << " ";
            for (int i = 0; i < n; i++) {
                if (nodes[i].parent == cur) {
                    queue[rear] = i;
                    rear++;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    ParentTree t;

    cout << "===== 双亲表示法的树 =====" << endl;
    cout << "【创建树】" << endl;
    t.create();

    cout << "【树的存储结构】" << endl;
    t.printTree();

    cout << "【层序遍历】" << endl;
    t.levelOrder();

    cout << endl << "【空树测试】" << endl;
    ParentTree emptyTree;
    emptyTree.create();
    emptyTree.levelOrder();

    cout << endl << "【单结点测试】" << endl;
    ParentTree singleTree;
    singleTree.create();
    singleTree.levelOrder();

    return 0;
}
