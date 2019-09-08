//
// Created by Yiheng Shu on 2019/9/8.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 110;
int nLine, src, dest;

struct Edge {
    int from;
    int to;
    int w;

    Edge(int from, int to, int w) : from(from), to(to), w(w) {}
};

vector<Edge> graph[maxn];
bool vis[maxn];
int dis[maxn];
const int inf = 0x3f3f3f3f;

struct cmp {
    bool operator()(const int a, const int b) {
        return dis[a] > dis[b];
    }
};

void f() {
    for (int i = 0; i < maxn; i++) {
        dis[i] = inf;
    }
    dis[src] = 0;
    priority_queue<int, vector<int>, cmp> pq;
    pq.push(src);

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        for (int i = 0; i < graph[cur].size(); i++) {
            Edge &e = graph[cur][i];
            if (dis[e.to] > dis[cur] + e.w) {
                dis[e.to] = dis[cur] + e.w;
                pq.push(e.to);
            }
        }
    }
}

int main() {
    cin >> nLine >> src >> dest;
    for (int lineIdx = 1; lineIdx <= nLine; lineIdx++) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int to;
            cin >> to;
            if (i == 0) {
                graph[lineIdx].push_back(Edge(lineIdx, to, 0));
            } else {
                graph[lineIdx].push_back(Edge(lineIdx, to, 1));
            }
        }
    }

    f();
    if (dis[dest] == inf) cout << -1;
    else cout << dis[dest];
    return 0;
}