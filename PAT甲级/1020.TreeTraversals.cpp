//
// Created by Yiheng Shu on 2019/8/28.
//

/*
Sample Input:

7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:

4 1 6 3 5 7 2
 */

// 给定一棵二叉树的后序和中序遍历结果，输出层次遍历的结果

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val) {
        left = right = NULL;
    }

    TreeNode() : val(0), left(NULL), right(NULL) {}
};

int n;
vector<int> postOrder;
vector<int> inOrder;
TreeNode *root;

void input() {
    cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        postOrder.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        inOrder.push_back(t);
    }
}

/**
 * 根据后序遍历和中序遍历构建二叉树
 * @param ps 后序遍历数组起始索引
 * @param pe 后序遍历数组终止索引
 * @param is 中序遍历数组起始索引
 * @param ie 中序遍历数组终止索引
 * @return 返回二叉树根结点
 */
TreeNode *build(int ps, int pe, int is, int ie) {
    if (ps > pe || is > ie) return NULL;
    TreeNode *res = new TreeNode();
    res->val = postOrder[pe];
    int rootIdx;
    for (rootIdx = is; rootIdx <= ie; rootIdx++) {
        if (inOrder[rootIdx] == res->val)
            break;
    }
    int leftLen = rootIdx - is;
    int rightLen = ie - rootIdx;

    res->left = build(ps, ps + leftLen - 1, is, is + leftLen - 1);
    res->right = build(pe - rightLen, pe - 1, rootIdx + 1, ie);
    return res;
}

void solve() {
    root = build(0, postOrder.size() - 1, 0, inOrder.size() - 1);
}

void output() {
    bool first = true;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();

        while (size--) {
            TreeNode *cur = que.front();
            que.pop();
            if (first) first = false;
            else cout << " ";
            cout << cur->val;
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}