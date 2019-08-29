//
// Created by Yiheng Shu on 2019/8/28.
//

/*
Sample Input 1:

5
1 2
1 3
1 4
2 5
Sample Output 1:

3
4
5
Sample Input 2:

5
1 3
1 4
2 5
3 4
Sample Output 2:

Error: 2 components
 */

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 10005;
const int inf = 0x3f3f3f3f;
vector<int> graph[maxn];
int f[maxn];
int depth[maxn];
bool vis[maxn];

int n;

void init() {
    for (int i = 0; i < maxn; i++) {
        f[i] = i;
    }
}

int find(int x) {
    while (x != f[x]) {
        x = f[x];
    }
    return x;
}

void Union(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        f[fx] = fy;
    }
}

void input() {
    cin >> n;
    int from, to;
    init();
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
        Union(from, to);
    }
}

/**
 * 求最大深度
 * @param root 根结点
 * @return 以root为根结点的树的最大深度
 */
int getDepth(int root) {
    int res = 0;
    vis[root] = true;
    for (int i = 0; i < graph[root].size(); i++) {
        if (vis[graph[root][i]]) continue;
        res = max(getDepth(graph[root][i]), res);
    }
    return res + 1;
}

void solve() {
    // 首先检查连通分量数
    int componentCnt = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) componentCnt++;
    }
    if (componentCnt > 1) {
        cout << "Error: " << componentCnt << " components";
        return;
    }

    // 只有一个连通分量，求最大深度
    int maxDepth = 0;
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + maxn - 1, false);
        maxDepth = max(maxDepth, getDepth(i));
    }
    bool first = true;
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + maxn - 1, false);
        if (getDepth(i) == maxDepth) {
            if (first) first = false;
            else cout << "\n";
            cout << i;
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}