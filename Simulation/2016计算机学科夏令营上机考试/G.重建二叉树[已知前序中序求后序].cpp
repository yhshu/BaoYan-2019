//
// Created by syh on 19-5-7.
//

/*
 * 2255:重建二叉树
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一棵二叉树的前序遍历和中序遍历的结果，求其后序遍历。

输入
输入可能有多组，以EOF结束。
每组输入包含两个字符串，分别为树的前序遍历和中序遍历。每个字符串中只包含大写字母且互不重复。
输出
对于每组输入，用一行来输出它后序遍历结果。
样例输入
DBACEGF ABCDEFG
BCAD CBAD
样例输出
ACBFGED
CDAB
提示
以英文题面为准
 */

#include <iostream>
#include <string>

using namespace std;

class TreeNode {
public:
    TreeNode *left;
    TreeNode *right;
    char ch;

    TreeNode(char ch) : ch(ch), left(NULL), right(NULL) {}
};

void postOrder(TreeNode *root) {
    // 1.left, 2. right and 3. root
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->ch;
}

TreeNode *buildTree(string preOrder, string inOrder) {
    if (preOrder.size() != inOrder.size()) {
        cout << "[Debug] The size of the two strings does not match, preOrder: " << preOrder << ", inOrder: " << inOrder
             << "\n";
        return NULL;
    }
    if (preOrder.empty() && inOrder.empty())
        return NULL;

    const int size = preOrder.size();
    int rootPos = inOrder.find(preOrder[0]);
    TreeNode *root = new TreeNode(preOrder[0]);
    const int len1 = rootPos;
    const int len2 = size - rootPos - 1;
    root->left = buildTree(preOrder.substr(1, len1), inOrder.substr(0, len1));
    root->right = buildTree(preOrder.substr(len1 + 1, len2), inOrder.substr(rootPos + 1, len2));
    return root;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string preOrder, inOrder;

    while (cin >> preOrder) {
        cin >> inOrder;
        TreeNode *root = buildTree(preOrder, inOrder);
        postOrder(root);
        cout << endl;
    }
    return 0;
}
