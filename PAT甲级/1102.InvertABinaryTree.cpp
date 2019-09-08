//
// Created by Yiheng Shu on 2019/9/8.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 15;

struct Node {
    int left;
    int right;

    Node() { left = right = -1; }
};

Node nodes[maxn];
vector<int> lo;
vector<int> io;
bool root[maxn];
int nLine;

int findRoot() {
    int i;
    for (i = 0; i < nLine; i++) {
        if (!root[i])
            return i;
    }
    return i;
}

void levelOrder() {
    queue<int> que;
    que.push(findRoot());

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        lo.push_back(cur);
        if (nodes[cur].left != -1) que.push(nodes[cur].left);
        if (nodes[cur].right != -1) que.push(nodes[cur].right);
    }
}

void inOrder(int root) {
    if (nodes[root].left != -1) inOrder(nodes[root].left);
    io.push_back(root);
    if (nodes[root].right != -1) inOrder(nodes[root].right);
}

int main() {
    cin >> nLine;

    for (int i = 0; i < nLine; i++) {
        char left, right;
        cin >> left >> right;
        if ('0' <= left && left <= '9') {
            nodes[i].right = left - '0';
            root[left - '0'] = true;
        }
        if ('0' <= right && right <= '9') {
            nodes[i].left = right - '0';
            root[right - '0'] = true;
        }
    }

    int r = findRoot();
    levelOrder();
    inOrder(r);

    for (int i = 0; i < lo.size(); i++) {
        if (i) printf(" ");
        printf("%d", lo[i]);
    }
    printf("\n");
    for (int i = 0; i < io.size(); i++) {
        if (i) printf(" ");
        printf("%d", io[i]);
    }
    return 0;
}