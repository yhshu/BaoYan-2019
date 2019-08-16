//
// Created by Yiheng Shu on 2019-08-15.
//

/*
Sample Input:

5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output:

2 4
 */

#include <iostream>
#include <queue>
#include <map>

using namespace std;

const int maxn = 510;

int n;      // 顶点数
int m;      // 边数
int c1, c2; // 起点和终点

class Edge {
public:
    int to;
    int wei;

    Edge(int to, int wei) : to(to), wei(wei) {}
};


int num[maxn]; // 各城市救援队数量
vector<Edge> graph[maxn];
int from, to, wei;
int dis[maxn];

struct cmp {
    bool operator()(const int a, const int b) {
        return dis[a] > dis[b];
    }
};

priority_queue<int, vector<int>, cmp> pq;
const int inf = 0x3f3f3f3f;
int ans1[maxn]; // 记录从起点到终点的路径长度到方案数的映射
int ans2[maxn]; // 记录最短路径的所有方案中可召唤的最大救援队数

void input() {
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> wei;
        graph[from].push_back(Edge(to, wei));
        graph[to].push_back(Edge(from, wei));
    }
}

void Dijkstra() {
    fill(dis, dis + n, inf);
    dis[c1] = 0;
    ans1[c1] = 1;
    ans2[c1] = num[c1];
    pq.push(c1);

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            Edge e = graph[cur][i];

            if (dis[e.to] > dis[cur] + e.wei) {
                dis[e.to] = dis[cur] + e.wei;
                ans1[e.to] = ans1[cur];
                ans2[e.to] = ans2[cur] + num[e.to];
                pq.push(e.to);
            } else if (dis[e.to] == dis[cur] + e.wei) {
                ans1[e.to] += ans1[cur];
                ans2[e.to] = max(ans2[e.to], ans2[cur] + num[e.to]);
            }
        }
    }
}

void output() {
    cout << ans1[c2] << " " << ans2[c2];
}

int main() {
    input();
    Dijkstra();
    output();
    return 0;
}
