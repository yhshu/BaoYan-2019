//
// Created by Yiheng Shu on 2019/9/6.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int isComplete = 1, afterNull = 0;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

// 旋转操作的步骤
// 1. 指定要返回的新的根结点
// 2. 将新的根结点的需要移动的子树移动为原根结点的子树
// 3. 将原根结点拼接为新根结点的子结点

TreeNode *leftRotate(TreeNode *root) {
    TreeNode *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

TreeNode *rightRotate(TreeNode *root) {
    TreeNode *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

TreeNode *leftRightRotate(TreeNode *root) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
}

TreeNode *rightLeftRotate(TreeNode *root) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
}

int getHeight(TreeNode *root) {
    if (root == nullptr) return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return max(l, r) + 1;
}

/**
 * 向 AVL 树中插入值
 * @param root AVL 树根结点
 * @param val 插入值
 * @return 插入后的 AVL 树根结点
 */
TreeNode *insert(TreeNode *root, int val) {
    if (root == nullptr) {  // 插入为新结点
        root = new TreeNode();
        root->val = val;
    } else if (val < root->val) { // 插入到左子树
        root->left = insert(root->left, val);
        int l = getHeight(root->left), r = getHeight(root->right);
        if (l - r >= 2) { // 左子树过高
            if (val < root->left->val)
                root = rightRotate(root);
            else
                root = leftRightRotate(root);
        }
    } else { // 插入到右子树
        root->right = insert(root->right, val);
        int l = getHeight(root->left), r = getHeight(root->right);
        if (r - l >= 2) { // 右子树过高
            if (val > root->right->val)
                root = leftRotate(root);
            else
                root = rightLeftRotate(root);
        }
    }
    return root;
}

vector<int> levelOrder(TreeNode *root) {
    vector<int> v;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        TreeNode *cur = que.front();
        que.pop();

        v.push_back(cur->val);
        if (cur->left) {
            if (afterNull) isComplete = 0;
            que.push(cur->left);
        } else afterNull = 1;
        if (cur->right) {
            if (afterNull) isComplete = 0;
            que.push(cur->right);
        } else afterNull = 1;
    }
    return v;
}

int main() {
    int nNode;
    cin >> nNode;
    TreeNode *root = nullptr;
    for (int i = 0; i < nNode; i++) {
        int t;
        cin >> t;
        root = insert(root, t);
    }

    vector<int> v = levelOrder(root);
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n%s", isComplete ? "YES" : "NO");
    return 0;
}
