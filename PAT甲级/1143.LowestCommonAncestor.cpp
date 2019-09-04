//
// Created by Yiheng Shu on 2019/9/4.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool firstline = true;

void nextline() {
    if (firstline) firstline = false;
    else cout << endl;
}

int nPair, nNode;
vector<int> preorder;
set<int> nodeSet;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val) { left = right = NULL; }
};

TreeNode *build(int start, int end) {
    if (start > end) return NULL;
    if (start == end) return new TreeNode(preorder[start]);
    int rootVal = preorder[start];
    TreeNode *root = new TreeNode(rootVal);
    int i;
    for (i = start + 1; i <= end; i++) {
        if (preorder[i] > rootVal) break;
    }
    root->left = build(start + 1, i - 1);
    root->right = build(i, end);
    return root;
}

TreeNode *LCA(TreeNode *root, int p, int q) {
    if (root == NULL || root->val == p || root->val == q) return root;

    TreeNode *left = LCA(root->left, p, q);
    TreeNode *right = LCA(root->right, p, q);

    if (left == NULL) return right;
    if (right == NULL) return left;
    return root;
}

int main() {
    cin >> nPair >> nNode;
    for (int i = 0; i < nNode; i++) {
        int t;
        cin >> t;
        preorder.push_back(t);
        nodeSet.insert(t);
    }

    TreeNode *root = build(0, preorder.size() - 1);

    for (int i = 0; i < nPair; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        nextline();
        if (nodeSet.find(node1) == nodeSet.end() && nodeSet.find(node2) != nodeSet.end()) {
            cout << "ERROR: " << node1 << " is not found.";
            continue;
        } else if (nodeSet.find(node2) == nodeSet.end() && nodeSet.find(node1) != nodeSet.end()) {
            cout << "ERROR: " << node2 << " is not found.";
            continue;
        } else if (nodeSet.find(node1) == nodeSet.end() && nodeSet.find(node2) == nodeSet.end()) {
            cout << "ERROR: " << node1 << " and " << node2 << " are not found.";
            continue;
        }

        TreeNode *lca = LCA(root, node1, node2);
        if (lca->val == node1 || lca->val == node2) {
            cout << lca->val << " is an ancestor of " << ((lca->val == node1) ? node2 : node1) << ".";
        } else {
            cout << "LCA of " << node1 << " and " << node2 << " is " << lca->val << ".";
        }
    }
    return 0;
}