//
// Created by Yiheng Shu on 2019-08-20.
//

// 参考背包九讲 分组背包问题

#include <iostream>

using namespace std;

const int maxn = 32005;
const int maxm = 65;
int n, m;                      // 金额，物品数
int v[maxm], p[maxm], q[maxm]; // 价格，重要度，附件
int dp[maxn];                  // dp[i] 表示不超过金额 i 可获得的最大加权价值
int gdp[maxn];                 // 用于某一分组的 dp，gdp[i] 表示当前分组中不超过金额 i 可获得的最大加权价值

void input() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> p[i] >> q[i]; // 价格，权重，附件信息
        p[i] *= v[i];
    }
}

void solve() {
    for (int i = 1; i <= m; i++) {
        if (!q[i]) {  // 该物品是主件
            // 考虑放入主件
            for (int j = 1; j < v[i]; j++)
                gdp[j] = 0;
            for (int j = v[i]; j <= n; j++)
                gdp[j] = dp[j - v[i]] + p[i];

            // 考虑放入附件
            for (int j = 1; j <= m; j++) {
                if (q[j] == i) {    // 找到属于该主件的附件
                    for (int k = n; k >= v[i] + v[j]; k--) {
                        gdp[k] = max(gdp[k], gdp[k - v[j]] + p[j]);
                    }
                }
            }
            for (int j = v[i]; j <= n; j++)
                dp[j] = max(dp[j], gdp[j]);
        }
    }
}

void output() {
    cout << dp[n];
}

int main() {
    input();
    solve();
    output();
    return 0;
}
