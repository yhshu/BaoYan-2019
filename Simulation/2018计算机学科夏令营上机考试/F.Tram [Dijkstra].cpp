//
// Created by syh on 19-3-17.
//

/*
 * 百练OJ 1847
 * F:Tram
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Tram network in Zagreb consists of a number of intersections and rails connecting some of them. In every intersection there is a switch pointing to the one of the rails going out of the intersection. When the tram enters the intersection it can leave only in the direction the switch is pointing. If the driver wants to go some other way, he/she has to manually change the switch.

When a driver has do drive from intersection A to the intersection B he/she tries to choose the route that will minimize the number of times he/she will have to change the switches manually.

Write a program that will calculate the minimal number of switch changes necessary to travel from intersection A to intersection B.
输入
The first line of the input contains integers N, A and B, separated by a single blank character, 2 <= N <= 100, 1 <= A, B <= N, N is the number of intersections in the network, and intersections are numbered from 1 to N.

Each of the following N lines contain a sequence of integers separated by a single blank character. First number in the i-th line, Ki (0 <= Ki <= N-1), represents the number of rails going out of the i-th intersection. Next Ki numbers represents the intersections directly connected to the i-th intersection.Switch in the i-th intersection is initially pointing in the direction of the first intersection listed.
输出
The first and only line of the output should contain the target minimal number. If there is no route from A to B the line should contain the integer "-1".
样例输入
3 2 1
2 2 3
2 3 1
2 1 2
样例输出
0
 */

/*
 * 本题为有向图最短路问题，所有路径的代价可能是0或1
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f

class Edge {
public:
    int dis;
    int to;

    Edge(int dis, int to) : dis(dis), to(to) {}
};

const int maxn = 100 + 10;
int dis[maxn]; // dis[i]是起点到点i的距离
int n, a, b; // 顶点数量，起点，终点
vector<Edge> nei[maxn]; // 邻接表

struct cmp {
    bool operator()(int a, int b) {
        return dis[a] > dis[b];
    }
};

priority_queue<int, vector<int>, cmp> que; // 堆优化
bool vis[maxn];

void init() {
    for (int i = 0; i <= maxn; i++) {
        dis[i] = INF;
    }
}

void Dijkstra() {
    dis[a] = 0;
    que.push(a);

    while (!que.empty()) {
        int cur = que.top();
        que.pop();
        vis[cur] = true;

        for (int i = 0; i < nei[cur].size(); i++) {
            Edge e = nei[cur][i];
            if (vis[e.to]) continue;
            if (e.dis + dis[cur] < dis[e.to])
                dis[e.to] = dis[cur] + e.dis;
            que.push(e.to);
        }
    }
}

int main() {
    init();

    // 输入
    cin >> n >> a >> b;
    int m;
    for (int u = 1; u <= n; u++) {
        cin >> m;
        for (int j = 1; j <= m; j++) {
            int v, d;
            cin >> v;
            if (j == 1) d = 0;
            else d = 1;
            Edge edge(d, v);
            nei[u].push_back(edge);
        }
    }

    Dijkstra();
    int res = dis[b];
    if (res == INF)
        res = -1;
    cout << res << endl;
    return 0;
}
