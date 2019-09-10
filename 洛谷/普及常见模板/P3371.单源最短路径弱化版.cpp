//
// Created by Yiheng Shu on 2019/9/9.
//

#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

const int maxm = 500010;
const int maxn = 10010;
const int inf = 0x7fffffff; // 不可达时输出 INT_MAX

int cnt;
struct Edge {
    int to;
    int w;
    int next;
};

struct Node {
    int pos;
    int dis;

    bool operator<(const Node &node) const {
        return dis > node.dis;
    }
};

Edge e[maxm];
int head[maxn];
int dis[maxn];
bool vis[maxn];

void addEdge(int from, int to, int w) {
    cnt++;
    e[cnt].w = w;
    e[cnt].to = to;
    e[cnt].next = head[from];
    head[from] = cnt;
}

int nNode, nEdge, src;

void Dijkstra() {
    for (int i = 0; i < maxn; i++) dis[i] = inf;

    priority_queue<Node> pq;
    dis[src] = 0;
    pq.push((Node) {src, 0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (vis[cur.pos]) continue;
        vis[cur.pos] = true;
        for (int i = head[cur.pos]; i; i = e[i].next) {
            Edge &edge = e[i];
            if (dis[cur.pos] != inf && dis[edge.to] > dis[cur.pos] + edge.w) {
                dis[edge.to] = dis[cur.pos] + edge.w;
                if (!vis[edge.to]) {
                    pq.push((Node) {edge.to, dis[edge.to]});
                }
            }
        }
    }
}

int main() {
    cin >> nNode >> nEdge >> src;
    for (int i = 0; i < nEdge; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        addEdge(from, to, w);
    }

    Dijkstra();
    for (int i = 1; i <= nNode; i++) {
        if (i > 1) printf(" ");
        printf("%d", dis[i]);
    }
    return 0;
}
