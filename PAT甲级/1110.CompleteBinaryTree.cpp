//
// Created by Yiheng Shu on 2019/9/18.
//

#include <iostream>
#include <queue>

using namespace std;

int nNode;

struct TreeNode {
    int val;
    int left;
    int right;

    TreeNode(int val) : val(val) { left = right = -1; }
};

const int maxn = 25;
TreeNode *treenodes[maxn];
bool root[maxn];
bool leaf = false;
bool judgeComplete = true;
int lastVal;

bool levelOrder(TreeNode *root) {
    if (!root) return true;
    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty()) {
        int size = que.size();
        while (size--) {
            TreeNode *cur = que.front();
            que.pop();

            if (cur->left == -1 && cur->right != -1) return false;
            if (leaf && (cur->left != -1 || cur->right != -1)) {
                return false;
            } else if (cur->left == -1) {
                leaf = true;
            }
            if (cur->left != -1) que.push(treenodes[cur->left]);
            if (cur->right != -1) que.push(treenodes[cur->right]);
            lastVal = cur->val;
        }
    }
    return true;
}

int main() {
    cin >> nNode;
    for (int nodeIdx = 0; nodeIdx < nNode; nodeIdx++) {
        string left, right;
        cin >> left >> right;
        TreeNode *treenode = new TreeNode(nodeIdx);
        if (left != "-") {
            treenode->left = stoi(left);
            root[stoi(left)] = true;
        }
        if (right != "-") {
            treenode->right = stoi(right);
            root[stoi(right)] = true;
        }
        treenodes[nodeIdx] = treenode;
    }

    int rootIdx = 0;
    for (int i = 0; i < nNode; i++) {
        if (!root[i]) {
            rootIdx = i;
            break;
        }
    }
//    printf("# %d\n", rootIdx);

    // 判定完全二叉树的一种方法是，层次遍历，首个叶结点出现之后的节点应该都是叶结点，否则该树不是完全二叉树
    bool judge = levelOrder(treenodes[rootIdx]);

    if (judge) {
        printf("YES %d", lastVal);
    } else {
        printf("NO %d", rootIdx);
    }
    return 0;
}
