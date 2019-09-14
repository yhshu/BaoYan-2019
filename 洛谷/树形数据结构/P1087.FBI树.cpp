//
// Created by Yiheng Shu on 2019/9/14.
//

#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int n;
string str;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() { left = right = NULL; }

    TreeNode(char val) : val(val) { left = right = NULL; }
};

void postOrder(TreeNode *root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c", root->val);
}

int main() {
    cin >> n;
    cin >> str;

    queue<TreeNode *> que;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1')
            que.push(new TreeNode('I'));
        else
            que.push(new TreeNode('B'));
    }

    while (que.size() > 1) {
        TreeNode *left = que.front();
        que.pop();
        TreeNode *right = que.front();
        que.pop();

        TreeNode *newNode = new TreeNode();
        if (left->val == 'B' && right->val == 'B')
            newNode->val = 'B';
        else if (left->val == 'I' && right->val == 'I')
            newNode->val = 'I';
        else
            newNode->val = 'F';
        newNode->left = left;
        newNode->right = right;
        que.push(newNode);
    }
    postOrder(que.front());

    return 0;
}