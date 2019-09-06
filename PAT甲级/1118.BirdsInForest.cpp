//
// Created by Yiheng Shu on 2019/9/6.
//

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int maxn = 10010;
int f[maxn];
int nPic, nQuery;
unordered_set<int> nums;

void init() {
    for (int i = 0; i < maxn; i++) {
        f[i] = i;
    }
}

int find(int x) {
    int t = x;
    while (x != f[x])
        x = f[x];

    int a;
    while (t != x) {
        a = f[t];
        f[t] = x;
        t = a;
    }
    return x;
}

void Union(int x, int y) {
    int fx = find(x);
    int fy = find(y);

    if (fx != fy) {
        f[fx] = fy;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    init();
    cin >> nPic;
    int maxNo = 0;
    for (int i = 0; i < nPic; i++) {
        int len, first;
        cin >> len >> first;
        nums.insert(first);
        maxNo = max(maxNo, first);
        for (int j = 1; j < len; j++) {
            int t;
            cin >> t;
            Union(first, t);
            nums.insert(t);
            maxNo = max(maxNo, t);
        }
    }

    int nComponents = 0;
    for (int i = 1; i <= maxNo; i++) {
        if (f[i] == i) nComponents++;
    }

    printf("%d %d\n", nComponents, nums.size());

    cin >> nQuery;
    for (int i = 0; i < nQuery; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        if (find(node1) == find(node2)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
