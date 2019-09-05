//
// Created by Yiheng Shu on 2019/9/5.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

const int maxn = 25;
int nNode;

struct Node {
    string data;
    int left;
    int right;
};

vector<Node> nodes;
int root[maxn];
int topRootIdx;

string inorder(int rootIdx) {
    if (rootIdx <= 0 || rootIdx > nNode) return "";
    Node &node = nodes[rootIdx];
    if (node.left == -1 && node.right == -1) { // 叶结点
        return node.data;
    }
    // 非叶结点
    if (topRootIdx != rootIdx)
        return "(" + inorder(node.left) + node.data + inorder(node.right) + ")";
    return inorder(node.left) + node.data + inorder(node.right);
}

int main() {
    cin >> nNode;
    nodes = vector<Node>(nNode + 1);
    for (int i = 1; i <= nNode; i++) {
        string data;
        int left, right;
        cin >> data >> left >> right;
        if (left > 0) root[left] = true;
        if (right > 0) root[right] = true;
        nodes[i] = Node{data, left, right};
    }

    int rootIdx;
    for (int i = 1; i <= nNode; i++) {
        if (root[i] == false) {
            rootIdx = i;
            break;
        }
    }

    // 中序遍历二叉树，叶结点不加括号，非叶节点加括号，最外层不加括号
    topRootIdx = rootIdx;
    string res = inorder(rootIdx);
    printf("%s\n", res.c_str());
    return 0;
}