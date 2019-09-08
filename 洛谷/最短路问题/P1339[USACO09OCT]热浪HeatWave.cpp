//
// Created by Yiheng Shu on 2019-08-19.
//

// 最短路 Dijkstra 模板题

#include <iostream>
#include <vector>
#include <queue>

#define maxn 2510
using namespace std;

class Edge {
public:
    int to;
    int w;

    Edge(int to, int w) : to(to), w(w) {}
};

int dis[maxn];

struct cmp {
    bool operator()(const int a, const int b) {
        return dis[a] > dis[b];
    }
};

const int inf = 0x3f3f3f3f;
int T, C, Ts, Te; // 顶点数，边数，起点，终点
vector<Edge> graph[maxn];
priority_queue<int, vector<int>, cmp> pq;
bool vis[maxn];

void input() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> T >> C >> Ts >> Te;
    int from, to, w;
    for (int i = 0; i < C; i++) {
        cin >> from >> to >> w;
        graph[from].push_back(Edge(to, w));
        graph[to].push_back(Edge(from, w));
    }
}

void Dijkstra() {
    fill(dis, dis + maxn, inf);
    dis[Ts] = 0;
    pq.push(Ts);

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        if (vis[cur])continue;
        vis[cur] = true;

        for (int i = 0; i < graph[cur].size(); i++) {
            Edge nei = graph[cur][i];
            if (dis[nei.to] > dis[cur] + nei.w) {
                dis[nei.to] = dis[cur] + nei.w;
                pq.push(nei.to);
            }
        }
    }

}

void output() {
    cout << dis[Te];
}

int main() {
    input();
    Dijkstra();
    output();
}