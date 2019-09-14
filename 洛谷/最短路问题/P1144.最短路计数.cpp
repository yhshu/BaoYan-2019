//
// Created by Yiheng Shu on 2019/9/13.
//

#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

struct Edge {
    int from;
    int to;
    int w;
    int next;
};

struct Node {
    int dis;
    int pos;

    bool operator<(const Node &node) const {
        return dis > node.dis;
    }
};

int n, m;

const int maxn = 1000010;
const int maxm = 2000010;
Edge e[maxm];
int head[maxn];
int cnt;
int dis[maxn];
bool vis[maxn];
const int inf = 0x3f3f3f3f;
const int mod = 100003;
int ans[maxn];

/**
 * 标准的 Dijkstra 堆优化无法求解该题，因为最短路计数问题中，各顶点有被多次访问的可能
 * @param src 源点
 */
void Dijkstra(int src) {
    priority_queue<Node> pq;
    for (int i = 0; i < maxn; i++) dis[i] = inf;
    dis[src] = 0;
    ans[src] = 1;
    pq.push((Node) {0, src});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (vis[cur.pos]) continue;
        vis[cur.pos] = true;

        for (int i = head[cur.pos]; i; i = e[i].next) {
            if (dis[e[i].to] > dis[cur.pos] + e[i].w) {
                dis[e[i].to] = dis[cur.pos] + e[i].w;
                ans[e[i].to] = ans[cur.pos];
                pq.push((Node) {dis[e[i].to], e[i].to});
            } else if (dis[e[i].to] == dis[cur.pos] + e[i].w) {
                ans[e[i].to] += ans[cur.pos];
                ans[e[i].to] %= mod;
            }
        }
    }
}

int inq[maxn]; // 是否在队列中
void spfa(int src) {
    queue<int> que;
    for (int i = 0; i < maxn; i++) dis[i] = inf;
    dis[src] = 0;
    ans[src] = 1;
    que.push(src);
    inq[src] = 1;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        inq[cur] = 0;
        for (int i = head[cur]; i; i = e[i].next) {
            if (dis[e[i].to] > dis[cur] + 1) {
                dis[e[i].to] = dis[cur] + 1;
                ans[e[i].to] = ans[cur];
                if (!inq[e[i].to]) {
                    que.push(e[i].to);
                    inq[e[i].to] = 1;
                }
            } else if (dis[e[i].to] == dis[cur] + 1) {
                ans[e[i].to] += ans[cur];
                ans[e[i].to] %= mod;
            }
        }
    }
}

void addEdge(int from, int to, int w) {
    cnt++;
    e[cnt].from = from;
    e[cnt].to = to;
    e[cnt].w = w;
    e[cnt].next = head[from];
    head[from] = cnt;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        if (from == to) continue;
        addEdge(from, to, 1);
        addEdge(to, from, 1);
    }

    Dijkstra(1);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
