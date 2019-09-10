//
// Created by Yiheng Shu on 2019/9/9.
//

#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int nNode, nEdge;

struct Edge {
    int from;
    int to;
    int w;

    bool operator<(const Edge &e) const {
        return w > e.w;
    }

    Edge(int from, int to, int w) : from(from), to(to), w(w) {}
};

const int maxn = 5010;
priority_queue<Edge> pq;
int f[maxn];

void init() {
    for (int i = 0; i < maxn; i++) f[i] = i;
}

int find(int x) {
    int z = x;
    while (x != f[x]) x = f[x];
    while (z != x) { // 路径压缩提速明显
        int a = f[z];
        f[z] = x;
        z = a;
    }
    return x;
}

void Union(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> nNode >> nEdge;
    for (int i = 0; i < nEdge; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        pq.push(Edge(from, to, w));
    }

    int res = 0;
    init();
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        if (find(e.from) != find(e.to)) {
            Union(e.from, e.to);
            res += e.w;
        }
    }
    printf("%d", res);
    return 0;
}