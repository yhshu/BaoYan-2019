//
// Created by Yiheng Shu on 2019/9/9.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 10010;

int f[maxn];

void init() {
    for (int i = 0; i < maxn; i++) f[i] = i;
}

int find(int x) {
    int z = x;
    while (x != f[x]) x = f[x];
    while (z != x) {
        int a = f[z];
        f[z] = x;
        z = a;
    }
    return x;
}

void Union(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) { f[fx] = fy; }
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int command, x, y;
        cin >> command >> x >> y;

        if (command == 1) {
            Union(x, y);
        } else if (command == 2) {
            if (find(x) == find(y)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}