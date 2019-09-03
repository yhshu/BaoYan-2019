//
// Created by Yiheng Shu on 2019/9/2.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int nNode, nQuery;
bool firstLine = true;

void nextline() {
    if (firstLine) firstLine = false;
    else cout << endl;
}

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val) { left = right = NULL; }
};

TreeNode *build(const vector<int> &inorder, const vector<int> &preorder, int is, int ie, int ps, int pe) {
    if (is > ie || ps > pe) return NULL;
    TreeNode *root = new TreeNode(preorder[ps]);
    int inorderRootIdx;
    for (inorderRootIdx = is; inorderRootIdx <= ie; inorderRootIdx++) {
        if (inorder[inorderRootIdx] == root->val) break;
    }

    int leftLen = inorderRootIdx - is;
    root->left = build(inorder, preorder, is, is + leftLen - 1, ps + 1, ps + leftLen);
    root->right = build(inorder, preorder, inorderRootIdx + 1, ie, ps + leftLen + 1, pe);
    return root;
}

TreeNode *LCA(TreeNode *root, int p, int q) {
    if (!root || root->val == p || root->val == q) return root;

    TreeNode *left = LCA(root->left, p, q);
    TreeNode *right = LCA(root->right, p, q);
    if (left == NULL) return right;
    if (right == NULL) return left;
    return root;
}

int main() {
    cin >> nQuery >> nNode;

    vector<int> inorder;
    vector<int> preorder;
    set<int> nodeSet;

    for (int i = 0; i < nNode; i++) {
        int t;
        cin >> t;
        inorder.push_back(t);
        nodeSet.insert(t);
    }
    for (int i = 0; i < nNode; i++) {
        int t;
        cin >> t;
        preorder.push_back(t);
    }

    TreeNode *root = build(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1); // 构建二叉树

    for (int i = 0; i < nQuery; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        // 首先判断 node1 和 node2 是否都在树中
        set<int>::iterator node1it = nodeSet.find(node1);
        set<int>::iterator node2it = nodeSet.find(node2);

        nextline();
        if (node1it == nodeSet.end() && node2it != nodeSet.end()) {
            cout << "ERROR: " << node1 << " is not found.";
            continue;
        } else if (node1it != nodeSet.end() && node2it == nodeSet.end()) {
            cout << "ERROR: " << node2 << " is not found.";
            continue;
        } else if (node1it == nodeSet.end() && node2it == nodeSet.end()) {
            cout << "ERROR: " << node1 << " and " << node2 << " are not found.";
            continue;
        }

        TreeNode *lca = LCA(root, node1, node2);
        if (lca->val == node1 || lca->val == node2)
            cout << lca->val << " is an ancestor of " << ((lca->val == node1) ? node2 : node1) << ".";
        else
            cout << "LCA of " << node1 << " and " << node2 << " is " << lca->val << ".";
    }
    return 0;
}
