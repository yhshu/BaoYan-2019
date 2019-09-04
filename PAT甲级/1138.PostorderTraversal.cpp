//
// Created by Yiheng Shu on 2019/9/4.
//

#include <iostream>
#include <vector>

using namespace std;

int nNode;
vector<int> preorder;
vector<int> inorder;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val) { left = right = NULL; }
};

TreeNode *build(int ps, int pe, int is, int ie) {
    if (ps > pe || is > ie) return NULL;
    int rootVal = preorder[ps];
    TreeNode *root = new TreeNode(rootVal);

    int nodeIdx;
    for (nodeIdx = is; nodeIdx <= ie; nodeIdx++) {
        if (inorder[nodeIdx] == rootVal) break;
    }

    int leftLen = nodeIdx - is;
    root->left = build(ps + 1, ps + leftLen, is, nodeIdx - 1);
    root->right = build(ps + leftLen + 1, pe, nodeIdx + 1, ie);
    return root;
}

vector<int> res;

void postOrder(TreeNode *root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    res.push_back(root->val);
}

int main() {
    cin >> nNode;
    for (int i = 0; i < nNode; i++) {
        int node;
        cin >> node;
        preorder.push_back(node);
    }
    for (int i = 0; i < nNode; i++) {
        int node;
        cin >> node;
        inorder.push_back(node);
    }

    TreeNode *root = build(0, preorder.size() - 1, 0, inorder.size() - 1);
    postOrder(root);
    cout << res[0];
    return 0;
}