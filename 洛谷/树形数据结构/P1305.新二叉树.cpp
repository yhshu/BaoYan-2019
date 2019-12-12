//
// Created by Yiheng Shu on 2019/9/19.
//

#include <iostream>
#include <cstdio>

using namespace std;

int nNode;
const int maxn = 30;
bool notRoot[maxn];
bool valid[maxn];

struct TreeNode {
    char val;
    int left;
    int right;

    TreeNode(char val) : val(val) { left = right = -1; }
};

TreeNode *nodes[maxn];

void preOrder(TreeNode *root) {
    if (!root) return;
    printf("%c", root->val);
    if (root->left != -1)
        preOrder(nodes[root->left]);
    if (root->right != -1)
        preOrder(nodes[root->right]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> nNode;
    for (int i = 0; i < nNode; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        TreeNode *treenode = new TreeNode(root);
        valid[root - 'a'] = true;
        nodes[root - 'a'] = treenode;
        if (left != '*') {
            treenode->left = left - 'a';
            notRoot[left - 'a'] = true;
            valid[left - 'a'] = true;
        }
        if (right != '*') {
            treenode->right = right - 'a';
            notRoot[right - 'a'] = true;
            valid[right - 'a'] = true;
        }
    }

    int rootIdx = 0;
    for (int i = 0; i < nNode; i++) {
        if (!notRoot[i] && valid[i]) {
            rootIdx = i;
            break;
        }
    }

    preOrder(nodes[rootIdx]);
    return 0;
}