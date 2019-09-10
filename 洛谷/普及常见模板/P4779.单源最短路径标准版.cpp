//
// Created by Yiheng Shu on 2019/9/9.
//

#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 100010, maxm = 200010;

struct Edge {
    int to, dis, next;
};

Edge e[maxm];
int head[maxn], dis[maxn], cnt;
bool vis[maxn];
int n, m, s;
const int inf = 0x3f3f3f3f;

void addEdge(int from, int to, int w) {
    cnt++;
    e[cnt].dis = w;
    e[cnt].to = to;
    e[cnt].next = head[from];
    head[from] = cnt;
}

struct Node {
    int dis;
    int pos;

    bool operator<(const Node &node) const {
        return dis > node.dis;
    }
};

priority_queue<Node> pq;

void dijkstra() {
    dis[s] = 0;
    pq.push((Node) {0, s});

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (vis[node.pos]) continue;
        vis[node.pos] = true;

        for (int i = head[node.pos]; i; i = e[i].next) {
            Edge edge = e[i];
            if (dis[edge.to] > dis[node.pos] + edge.dis) {
                dis[edge.to] = dis[node.pos] + edge.dis;
                pq.push((Node) {dis[edge.to], edge.to});
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; ++i)dis[i] = inf;
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        addEdge(u, v, d);
    }
    dijkstra();
    for (int i = 1; i <= n; i++) {
        if (i > 1)printf(" ");
        printf("%d", dis[i]);
    }
    return 0;
}
