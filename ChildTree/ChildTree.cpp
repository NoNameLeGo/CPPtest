#include <iostream>

using namespace std;

const int MAX = 20;

struct ChildNode {
    int child;
    ChildNode* next;
};

struct TreeNode {
    char data;
    ChildNode* firstChild;
};

class ChildTree {
private:
    TreeNode nodes[MAX];
    int n;

public:
    ChildTree() {
        n = 0;
    }

    void create() {
        cin >> n;
        cout << "结点个数：" << n << endl;
        for (int i = 0; i < n; i++) {
            int count;
            cin >> nodes[i].data >> count;
            nodes[i].firstChild = NULL;
            ChildNode* tail = NULL;

            for (int j = 0; j < count; j++) {
                int c;
                cin >> c;
                ChildNode* p = new ChildNode;
                p->child = c;
                p->next = NULL;
                if (tail == NULL) {
                    nodes[i].firstChild = p;
                }
                else {
                    tail->next = p;
                }
                tail = p;
            }

            cout << "结点" << i << "：" << nodes[i].data << "，孩子下标 ";
            ChildNode* p = nodes[i].firstChild;
            if (p == NULL) {
                cout << "无";
            }
            while (p != NULL) {
                cout << p->child << " ";
                p = p->next;
            }
            cout << endl;
        }
    }

    void preOrder(int index) {
        if (index < 0 || index >= n) {
            return;
        }
        cout << nodes[index].data << " ";
        ChildNode* p = nodes[index].firstChild;
        while (p != NULL) {
            preOrder(p->child);
            p = p->next;
        }
    }

    void preOrderAll() {
        if (n == 0) {
            cout << "空树，没有结点" << endl;
            return;
        }
        preOrder(0);
        cout << endl;
    }

    ~ChildTree() {
        for (int i = 0; i < n; i++) {
            ChildNode* p = nodes[i].firstChild;
            while (p != NULL) {
                ChildNode* temp = p->next;
                delete p;
                p = temp;
            }
        }
    }
};

int main()
{
    ChildTree t;

    cout << "===== 孩子表示法的树 =====" << endl;
    cout << "【创建树】" << endl;
    t.create();

    cout << "【先根遍历】" << endl;
    t.preOrderAll();

    cout << endl << "【空树测试】" << endl;
    ChildTree emptyTree;
    emptyTree.create();
    emptyTree.preOrderAll();

    cout << endl << "【单结点测试】" << endl;
    ChildTree singleTree;
    singleTree.create();
    singleTree.preOrderAll();

    return 0;
}
