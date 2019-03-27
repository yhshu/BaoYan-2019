#include <algorithm>
#include <iostream>

#define MAXN 101
using namespace std;

int Tree[MAXN];

int findRoot(int x) { // 查找代表集合的树的根结点
    if (Tree[x] == -1)
        return x;
    int ret = findRoot(Tree[x]);
    Tree[x] = ret;
    return ret;
}

struct Edge {
    int a, b;
    int cost;

    bool operator<(const Edge &e) const { return this->cost < e.cost; }
} edge[MAXN * MAXN / 2];

int main() {
    int n;
    while (cin >> n && n != 0) {
        int ans = 0;
        for (int i = 1; i <= n * (n - 1) / 2; i++) {
            cin >> edge[i].a >> edge[i].b >> edge[i].cost;
        }
        sort(edge + 1, edge + 1 + n * (n - 1) / 2); // Kruskal 算法
        for (int i = 1; i <= n; i++)
            Tree[i] = -1;
        for (int i = 1; i <= n * (n - 1) / 2; i++) {
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if (a != b) { // 尚未连通
                Tree[a] = b;
                ans += edge[i].cost;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
