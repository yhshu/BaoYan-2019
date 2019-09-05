//
// Created by Yiheng Shu on 2019/9/5.
//

/*
   每个结点是红色的，或者黑色的。
   根结点是黑色的。
   叶结点（NULL）是黑色的。
   红结点的子结点都是黑结点。即红结点的父结点和子结点都是黑结点。
   每个结点到叶结点的所有路径中，黑结点的数目相同。
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int nCase, nNode;
bool firstline = true;

void nextline() {
    if (firstline) firstline = false;
    else printf("\n");
}

class RedBlackTreeNode {
public:
    int val;
    int color;  // 1: black, 0: red
    RedBlackTreeNode *left;
    RedBlackTreeNode *right;

    RedBlackTreeNode(int val, int color) : val(val), color(color) { left = right = NULL; }
};

RedBlackTreeNode *build(const vector<int> &tree, int start, int end) {
    if (tree.empty() || start > end) return NULL;

    int rootVal = tree[start];
    int rootColor = 0;
    if (rootVal > 0) rootColor = 1;
    else rootVal = -rootVal;
    RedBlackTreeNode *root = new RedBlackTreeNode(tree[start], rootColor);

    int nodeIdx;
    for (nodeIdx = start + 1; nodeIdx <= end; nodeIdx++) {
        if (abs(tree[nodeIdx]) > rootVal) break;
    }
    root->left = build(tree, start + 1, nodeIdx - 1);
    root->right = build(tree, nodeIdx, end);
    return root;
}

bool judge(RedBlackTreeNode *root) {
    if (!root) return true;
    if (root->color == 0) {
        if (root->left && root->left->color == 0) return false;
        if (root->right && root->right->color == 0) return false;
    }
    return judge(root->left) && judge(root->right);
}

int blackNodeCnt(RedBlackTreeNode *root) {
    if (root == NULL) return 0;
    int l = blackNodeCnt(root->left);
    int r = blackNodeCnt(root->right);
    return root->color == 1 ? max(l, r) + 1 : max(l, r);
}

bool judge2(RedBlackTreeNode *root) {
    if (root == NULL) return true;
    int l = blackNodeCnt(root->left);
    int r = blackNodeCnt(root->right);
    if (l != r) return false;
    return judge2(root->left) && judge2(root->right);
}

int main() {
    cin >> nCase;
    vector<int> tree;
    for (int i = 0; i < nCase; i++) {
        tree.clear();

        cin >> nNode;
        for (int j = 0; j < nNode; j++) {
            int node;
            cin >> node;
            tree.push_back(node);
        }

        // 1. 判断根结点是否为黑结点
        bool isRedBlackTreeNode = true;
        RedBlackTreeNode *root = build(tree, 0, tree.size() - 1);
        if (root->color == 0) isRedBlackTreeNode = false;

        // 2. 判断红结点的子结点是否均为黑结点
        isRedBlackTreeNode = isRedBlackTreeNode && judge(root);

        // 3. 判断树的所有路径中的黑结点数量是否相同
        isRedBlackTreeNode = isRedBlackTreeNode && judge2(root);

        nextline();
        if (isRedBlackTreeNode) printf("Yes");
        else printf("No");
    }
    return 0;
}
