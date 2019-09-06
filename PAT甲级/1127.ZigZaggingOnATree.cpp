//
// Created by Yiheng Shu on 2019/9/5.
//

// LeetCode 原题，考查对层次遍历的理解

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val) { left = right = NULL; }
};

int nNode;
vector<int> inorder;
vector<int> postorder;
vector<int> zigzag;

TreeNode *build(int is, int ie, int ps, int pe) {
    if (is > ie || ps > pe) return NULL;
    TreeNode *root = new TreeNode(postorder[pe]);

    int rootIdx;
    for (rootIdx = is; rootIdx <= ie; rootIdx++) {
        if (inorder[rootIdx] == root->val) break;
    }

    int leftLen = rootIdx - is;
    root->left = build(is, rootIdx - 1, ps, ps + leftLen - 1);
    root->right = build(rootIdx + 1, ie, ps + leftLen, pe - 1);
    return root;
}

void reverse(queue<TreeNode *> &que) {
    stack<TreeNode *> s;
    while (!que.empty()) {
        s.push(que.front());
        que.pop();
    }

    while (!s.empty()) {
        que.push(s.top());
        s.pop();
    }
}

int main() {
    cin >> nNode;
    for (int i = 0; i < nNode; i++) {
        int t;
        cin >> t;
        inorder.push_back(t);
    }
    for (int i = 0; i < nNode; i++) {
        int t;
        cin >> t;
        postorder.push_back(t);
    }

    TreeNode *root = build(0, inorder.size() - 1, 0, postorder.size() - 1);
    queue<TreeNode *> que;
    que.push(root);
    bool lTor = false;
    while (!que.empty()) {
        int size = que.size();

        while (size--) {
            TreeNode *cur = que.front();
            que.pop();

            zigzag.push_back(cur->val);
            if (lTor) {
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            } else {
                if (cur->right) que.push(cur->right);
                if (cur->left) que.push(cur->left);
            }
        }
        reverse(que);
        lTor = !lTor;
    }

    for (int i = 0; i < zigzag.size(); i++) {
        if (i) printf(" ");
        printf("%d", zigzag[i]);
    }

    return 0;
}