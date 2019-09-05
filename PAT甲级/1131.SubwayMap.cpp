//
// Created by Yiheng Shu on 2019/9/5.
//

// todo

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 10010;

struct Edge {
    int from;
    int to;
    int line;
};

vector<Edge> graph[maxn];
Edge pre[maxn];
int dis[maxn];

void Dijkstra(int src) {
    queue<int> que;
    for (int i = 0; i < maxn; i++)
        dis[i] = inf;
    dis[src] = 0;
    que.push(src);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            Edge &edge = graph[cur][i];
            if (dis[edge.to] > dis[cur] + 1) {
                dis[edge.to] = dis[cur] + 1;
                que.push(edge.to);
                pre[edge.to] = edge;
            } else if (dis[edge.to] == dis[cur] + 1 && !) {

            }
        }
    }
}

int main() {
    int nLine;
    cin >> nLine;

    for (int lineIdx = 1; lineIdx <= nLine; lineIdx++) {
        int nStop, pre, cur;
        cin >> nStop >> pre;
        for (int stopIdx = 1; stopIdx < nStop; stopIdx++) {
            graph[pre].push_back(Edge{pre, cur, lineIdx});
            graph[cur].push_back(Edge{cur, pre, lineIdx});
            pre = cur;
        }
    }

    int nQuery;
    cin >> nQuery;
    for (int queryIdx = 0; queryIdx < nQuery; queryIdx++) {
        int src, dest;
        cin >> src >> dest;
        Dijkstra(src);
    }

    return 0;
}