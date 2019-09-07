//
// Created by Yiheng Shu on 2019/9/7.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val) { left = right = NULL; }
};

TreeNode *insert(TreeNode *root, int val) {
    if (!root) return new TreeNode(val);
    if (val > root->val) root->right = insert(root->right, val);
    else if (val <= root->val) root->left = insert(root->left, val);
    return root;
}

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty()) {
        vector<int> level;

        int size = que.size();
        while (size--) {
            TreeNode *cur = que.front();
            que.pop();

            level.push_back(cur->val);
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        res.push_back(level);
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int val;
    cin >> val;
    TreeNode *root = new TreeNode(val);
    for (int i = 1; i < n; i++) {
        cin >> val;
        insert(root, val);
    }

    vector<vector<int>> levels = levelOrder(root);
    int n1 = levels[levels.size() - 1].size();
    int n2 = levels[levels.size() - 2].size();
    printf("%d + %d = %d", n1, n2, n1 + n2);

    return 0;
}