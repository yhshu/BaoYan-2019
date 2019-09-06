//
// Created by Yiheng Shu on 2019/9/6.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int isComplete = 1, after = 0;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

TreeNode *leftRotate(TreeNode *root) {
    TreeNode *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

TreeNode *rightRotate(TreeNode *tree) {
    TreeNode *temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;
}

TreeNode *leftRightRotate(TreeNode *tree) {
    tree->left = leftRotate(tree->left);
    return rightRotate(tree);
}

TreeNode *rightLeftRotate(TreeNode *tree) {
    tree->right = rightRotate(tree->right);
    return leftRotate(tree);
}

int getHeight(TreeNode *tree) {
    if (tree == nullptr) return 0;
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    return max(l, r) + 1;
}

/**
 * 向 AVL 树中插入值
 * @param tree AVL 树根结点
 * @param val 插入值
 * @return 插入后的 AVL 树根结点
 */
TreeNode *insert(TreeNode *tree, int val) {
    if (tree == nullptr) {
        tree = new TreeNode();
        tree->val = val;
    } else if (val < tree->val) { // 插入到左子树
        tree->left = insert(tree->left, val);
        int l = getHeight(tree->left), r = getHeight(tree->right);
        if (l - r >= 2) {
            if (val < tree->left->val)
                tree = rightRotate(tree);
            else
                tree = leftRightRotate(tree);
        }
    } else { // 插入到右子树
        tree->right = insert(tree->right, val);
        int l = getHeight(tree->left), r = getHeight(tree->right);
        if (r - l >= 2) {
            if (val > tree->right->val)
                tree = leftRotate(tree);
            else
                tree = rightLeftRotate(tree);
        }
    }
    return tree;
}

vector<int> levelOrder(TreeNode *tree) {
    vector<int> v;
    queue<TreeNode *> que;
    que.push(tree);
    while (!que.empty()) {
        TreeNode *cur = que.front();
        que.pop();

        v.push_back(cur->val);
        if (cur->left) {
            if (after) isComplete = 0;
            que.push(cur->left);
        } else after = 1;
        if (cur->right) {
            if (after) isComplete = 0;
            que.push(cur->right);
        } else after = 1;
    }
    return v;
}

int main() {
    int nNode;
    cin >> nNode;
    TreeNode *tree = nullptr;
    for (int i = 0; i < nNode; i++) {
        int t;
        cin >> t;
        tree = insert(tree, t);
    }

    vector<int> v = levelOrder(tree);
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n%s", isComplete ? "YES" : "NO");
    return 0;
}
