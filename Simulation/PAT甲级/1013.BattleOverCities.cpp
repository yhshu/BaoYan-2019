//
// Created by Yiheng Shu on 2019-08-16.
//

/*
Sample Input:

3 2 3
1 2
1 3
1 2 3
Sample Output:

1
0
0
*/

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1005;

int n; // 顶点数量
int m; // 剩余边数
int k; // 检查的顶点数

int f[maxn];
vector<int> graph[maxn];

void input() {
    cin >> n >> m >> k;
    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
}


int find(int x) {
    int cur = x;
    while (x != f[x])
        x = f[x];

    // 路径压缩
    int t;
    while (cur != x) {
        t = cur;
        f[cur] = x;
        cur = f[t];
    }
    return x;
}

void Union(int x, int y) {
    //cout << "union: " << x << ", " << y << endl;
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        f[fx] = fy;
    }
}

int count() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) cnt++;
    }
    return cnt;
}

void solve() {
    input();

    int check;
    for (int i = 0; i < k; i++) {
        cin >> check;
        // 去掉 check 顶点后，求图中的强连通分量的数量
        // 使用并查集

        init();
        for (int j = 1; j <= n; j++) {
            if (j == check) continue;
            for (int k = 0; k < graph[j].size(); k++) {
                int nei = graph[j][k];
                if (nei == check) continue;
                Union(j, nei);
            }
        }
        int ans = count() - 2;  // count 是包含被检查顶点在内的连通分量数
        // 除去检查顶点，减 1；将所有连通分量连接，只需要比连通分量数少 1 的边
        if (i == 0)
            cout << ans;
        else cout << "\n" << ans;
    }
}

int main() {
    solve();
    return 0;
}


