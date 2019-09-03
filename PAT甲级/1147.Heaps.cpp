//
// Created by Yiheng Shu on 2019/9/3.
//

#include <iostream>
#include <vector>

using namespace std;

const int maxm = 1010;

int nTree, nNode;
int lo[maxm];
vector<int> po;
bool firstline = true;
int treeState;

void nextline() {
    if (firstline) firstline = false;
    else cout << endl;
}

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val) { left = right = NULL; }
};

TreeNode *build(int pos) {
    if (pos > nNode) {
        return NULL;
    }

    TreeNode *root = new TreeNode(lo[pos]);
    root->left = build(2 * pos);
    root->right = build(2 * pos + 1);
    if (root->left && treeState == 2 && lo[pos] < lo[2 * pos])treeState = 0;
    if (root->right && treeState == 2 && lo[pos] < lo[2 * pos + 1])treeState = 0;
    if (root->left && treeState == 1 && lo[pos] > lo[2 * pos])treeState = 0;
    if (root->right && treeState == 1 && lo[pos] > lo[2 * pos + 1])treeState = 0;
    return root;
}

void postOrder(TreeNode *root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    po.push_back(root->val);
}

int main() {
    cin >> nTree >> nNode;

    for (int treeIdx = 1; treeIdx <= nTree; treeIdx++) {
        // 输入顺序是二叉树层次遍历
        for (int nodeIdx = 1; nodeIdx <= nNode; nodeIdx++) {
            int node;
            cin >> node;
            lo[nodeIdx] = node;
        }

        // 判定大根堆/小根堆/不是堆
        if (lo[1] >= lo[2] && lo[1] >= lo[3]) treeState = 2;
        else if (lo[1] <= lo[2] && lo[1] <= lo[3]) treeState = 1;
        else treeState = 0;

        TreeNode *root = build(1);

        nextline();
        if (treeState == 2) cout << "Max Heap";
        else if (treeState == 1) cout << "Min Heap";
        else if (treeState == 0) cout << "Not Heap";

        // 输出后序遍历
        po.clear();
        postOrder(root);
        nextline();
        for (int postOrderIdx = 0; postOrderIdx < po.size(); postOrderIdx++) {
            if (postOrderIdx) cout << " ";
            cout << po[postOrderIdx];
        }
    }
    return 0;
}
