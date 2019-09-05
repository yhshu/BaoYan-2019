//
// Created by Yiheng Shu on 2019/9/5.
//

#include <iostream>
#include <set>

using namespace std;

const int maxn = 50010;
int numCnt[maxn];
int nQuery, nItem;

struct Node {
    int val, cnt;

    bool operator<(const Node &node) const {
        if (cnt != node.cnt) return cnt > node.cnt;
        return val < node.val;
    }
};

set<Node> numSet;  // set 是有序的

int main() {
    cin >> nQuery >> nItem;

    for (int i = 0; i < nQuery; i++) {
        int num;
        cin >> num;
        if (i) {
            printf("%d:", num);
            int cnt = 0;
            for (auto it = numSet.begin(); cnt < nItem && it != numSet.end(); it++) {
                printf(" %d", it->val);
                cnt++;
            }
            printf("\n");
        }
        auto it = numSet.find(Node{num, numCnt[num]});
        if (it != numSet.end()) numSet.erase(it);
        numCnt[num]++;
        numSet.insert(Node{num, numCnt[num]});
    }

    return 0;
}
