//
// Created by Yiheng Shu on 2019/9/18.
//

#include <iostream>
#include <cstdio>

using namespace std;

int n;

struct Edge {
    int to;
    int next;
};

const int maxn = 6010;
Edge e[maxn];
int cnt;
int head[maxn];
int dp[maxn][2];
// dp[i][0] 表示 i 不参加时的根为 i 的子树最优解，dp[i][1] 表示 i 参加时的根为 i 的子树最优解
bool notRoot[maxn];
bool vis[maxn];

void addEdge(int from, int to) {
    cnt++;
    e[cnt].to = to;
    e[cnt].next = head[from];
    head[from] = cnt;
}

void calc(int root) {
    vis[root] = true;
    for (int i = head[root]; i; i = e[i].next) {
        if (vis[e[i].to]) continue;
        calc(e[i].to);
        // 如果选择当前点，其所有子结点都不能选择
        dp[root][1] += dp[e[i].to][0];
        // 如果不选择当前点，每个子结点都可选可不选
        dp[root][0] += max(dp[e[i].to][0], dp[e[i].to][1]);
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][1];
    }
    for (int i = 0; i < n - 1; i++) {
        int l, k;
        cin >> l >> k;
        addEdge(k, l); // k 是 l 的上司
        notRoot[l] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!notRoot[i]) {  // 从可能的根结点开始 dfs
            calc(i);
            printf("%d", max(dp[i][0], dp[i][1]));
            return 0;
        }
    }
    return 0;
}