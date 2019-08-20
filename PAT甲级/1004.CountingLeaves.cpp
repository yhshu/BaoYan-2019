//
// Created by Yiheng Shu on 2019-08-16.
//

/*
Sample Input:

2 1
01 1 02

Sample Output:

0 1
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n;  // 结点总数
int m;  // 非叶结点的数量

class TreeNode {
public:
    int no; // 编号
    vector<TreeNode *> children;

    TreeNode(int no) : no(no) {}
};

map<int, TreeNode *> tree;

TreeNode *getTreeNode(int rootNo) {
    TreeNode *res = NULL;
    if (tree.find(rootNo) == tree.end()) {
        res = new TreeNode(rootNo);
        tree[rootNo] = res;
    }
    return tree[rootNo];
}

void input() {
    cin >> n >> m;
    int rootNo, child, childNum;
    for (int i = 0; i < m; i++) {
        cin >> rootNo >> childNum;
        TreeNode *root = getTreeNode(rootNo);

        for (int j = 0; j < childNum; j++) {
            cin >> child;
            root->children.push_back(getTreeNode(child));
        }
    }
}

void solve() {
    queue<TreeNode *> que;
    if (tree.find(1) == tree.end()) {  // 测试点 2 是 n = 0，即没有任何结点
        cout << 1;
        return;
    }

    que.push(tree[1]);
    bool first = true;

    while (!que.empty()) {
        int size = que.size();
        int levelAns = 0;
        while (size--) {
            TreeNode *cur = que.front();
            que.pop();

            if (cur->children.empty()) {
                levelAns++;
            } else {
                for (int i = 0; i < cur->children.size(); i++) {
                    que.push(cur->children[i]);
                }
            }
        }
        if (first) {
            first = false;
            cout << levelAns;
        } else
            cout << " " << levelAns;
    }
}

int main() {
    input();
    solve();
    return 0;
}
