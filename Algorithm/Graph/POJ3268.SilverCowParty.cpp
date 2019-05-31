
/*
 POJ 3268. Silver Cow Party

 * Silver Cow Party
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 33630		Accepted: 15057
Description

One cow from each of N farms (1 ≤ N ≤ 1000) conveniently numbered 1..N is going to attend the big cow party to be held at farm #X (1 ≤ X ≤ N). A total of M (1 ≤ M ≤ 100,000) unidirectional (one-way roads connects pairs of farms; road i requires Ti (1 ≤ Ti ≤ 100) units of time to traverse.

Each cow must walk to the party and, when the party is over, return to her farm. Each cow is lazy and thus picks an optimal route with the shortest time. A cow's return route might be different from her original route to the party since roads are one-way.

Of all the cows, what is the longest amount of time a cow must spend walking to the party and back?

Input

Line 1: Three space-separated integers, respectively: N, M, and X
Lines 2..M+1: Line i+1 describes road i with three space-separated integers: Ai, Bi, and Ti. The described road runs from farm Ai to farm Bi, requiring Ti time units to traverse.

Output

Line 1: One integer: the maximum of time any one cow must walk.
Sample Input

4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

Sample Output

10
Hint

Cow 4 proceeds directly to the party (3 units) and returns via farms 1 and 3 (7 units), for a total of 10 time units.
Source

USACO 2007 February Silver
 */

// 有向图中有 n 个结点，编号 1 ~ n，输入终点编号x，求其他结点到x结点来回最短路长度的最大值
// 本题思路是两次 SPFA 或 两次 Dijkstra

// 首先以 x 为源点，计算 x 到所有顶点的最短路
// 然后将有向图中的所有边反向，重新计算 x 到所有顶点的最短路
// 即可获得所有顶点到 x 往返的最短路的最大值

// 编程和调试过程中的注意点：
// 1. 使用邻接矩阵找反向边更容易实现，邻接表不易找反向边
// 2. 最好能处理重边的情况，重边中取最短边
// 3. Dijkstra 算法的堆优化，取到的下一个点是到源点最近的尚未访问过的点

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;

int N, M, X; // 顶点数，边数，目标顶点

class Edge {
public:
    int from;
    int to;
    int wei;

    Edge(int from, int to, int wei) : from(from), to(to), wei(wei) {}
};

struct cmp {
    bool operator()(const Edge &e1, const Edge &e2) const {
        return e1.wei > e2.wei;  // 这里不写 return，Code Blocks 不会报编译错误
    }
};

int g1[maxn][maxn];
int g2[maxn][maxn];
// 需要初始化
priority_queue<Edge, vector<Edge>, cmp> pq;
bool vis[maxn];
int dis1[maxn];
int dis2[maxn];
int ans;

void input() {
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            g1[i][j] = g2[i][j] = inf;
        }
    }
    int from, to, wei;
    for (int i = 0; i < M; i++) {
        cin >> from >> to >> wei;
        g2[to][from] = g1[from][to] = min(g1[from][to], wei);
    }
}

void Dijkstra(int dis[], int g[][maxn]) {
    for (int i = 0; i < maxn; i++) {
        dis[i] = inf;
        vis[i] = false;
    }
    dis[X] = 0;
    ans = 0;

    Edge firstEdge(X, X, 0);
    pq.push(firstEdge);

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        //cout << "Edge: " << cur.from << " " << cur.to << " " << cur.wei << " vis: " << vis[cur.to] << endl;

        if (vis[cur.to]) continue;
        vis[cur.to] = true;

        for (int i = 1; i <= N; i++) {
            //printf("g[%d][%d]: %d\n", cur.to, i, g[cur.to][i]);
            if (vis[i] || g[cur.to][i] == inf)
                continue;
            if (dis[i] > dis[cur.to] + g[cur.to][i]) {
                dis[i] = dis[cur.to] + g[cur.to][i];
                pq.push(Edge(cur.to, i, dis[i]));
            }
        }
    }
}

void solve() {
    Dijkstra(dis1, g1);
    Dijkstra(dis2, g2);

    for (int i = 1; i <= N; i++) {
        //cout << "dis[" << i << "]: " << dis1[i] << " "<<dis2[i] << endl;
        if (dis1[i] == inf || dis2[i] == inf) continue;
        ans = max(ans, dis1[i] + dis2[i]);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (cin >> N >> M >> X) {
        input();
        solve();
        cout << ans << endl;
    }
    return 0;
}
