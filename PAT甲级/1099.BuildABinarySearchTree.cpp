//
// Created by 舒意恒 on 2019/9/8.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int nLine;

const int maxn = 110;

struct Node {
    int val;
    int left;
    int right;

    Node() {
        val = 0;
        left = right = -1;
    };
};

Node nodes[maxn];

vector<int> nodeSeq;
vector<int> nums;
vector<int> lo;

void inOrder(int root) {
    if (nodes[root].left != -1) inOrder(nodes[root].left);
    nodeSeq.push_back(root);
    if (nodes[root].right != -1) inOrder(nodes[root].right);
}

int find(int nodeId) {
    for (int i = 0; i < nodeSeq.size(); i++) {
        if (nodeSeq[i] == nodeId) return i;
    }
}

void levelOrder() {
    queue<int> que;
    que.push(0);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        int numsId = find(cur);
        lo.push_back(nums[numsId]);

        if (nodes[cur].left != -1) que.push(nodes[cur].left);
        if (nodes[cur].right != -1) que.push(nodes[cur].right);
    }
}

int main() {
    cin >> nLine;
    for (int nodeIdx = 0; nodeIdx < nLine; nodeIdx++) {
        cin >> nodes[nodeIdx].left >> nodes[nodeIdx].right;
    }

    // 按树的结构，给结点排序，然后给结点填充值，进行层次遍历
    inOrder(0);
    for (int i = 0; i < nLine; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    sort(nums.begin(), nums.end());

    levelOrder();
    for (int i = 0; i < lo.size(); i++) {
        if (i) printf(" ");
        printf("%d", lo[i]);
    }

    return 0;
}