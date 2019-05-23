/**
Sample Input

4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
Sample Output

28
 */

// 使用并查集表示顶点是否在同一连通分量中
// 使用优先级队列维护还未访问的边

#include <iostream>
#include <queue>

using namespace std;

const int maxn = 110;

class Edge {
public:
    int u, v;
    int dis;

    Edge(int u, int v, int dis) : u(u), v(v), dis(dis) {}

    bool operator<(const Edge &edge) const {
        return this->dis > edge.dis;
    }
};

int f[maxn];

void init() {
    for (int i = 0; i < maxn; i++)
        f[i] = i;
}

int Find(int x) {
    while (x != f[x])
        x = f[x];
    return x;
}

void Union(int x, int y) {
    int fx = Find(x);
    int fy = Find(y);
    if (fx == fy) return;
    f[fx] = fy;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;

    while (cin >> n) {
        int dis;
        int edgeCnt = 0;
        int ans = 0;
        priority_queue<Edge> pq;
        init();

        // input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dis;
                if (i == j || dis == 0) continue;
                pq.push(Edge(i, j, dis));
            }
        }

        while (edgeCnt < n - 1) {
            Edge edge = pq.top();
            pq.pop();
            if (Find(edge.u) == Find(edge.v)) continue;
            Union(edge.u, edge.v);
            edgeCnt++;
            ans += edge.dis;
        }
        cout << ans << endl;
    }
    return 0;
}
