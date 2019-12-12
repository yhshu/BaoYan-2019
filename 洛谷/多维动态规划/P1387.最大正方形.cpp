//
// Created by Yiheng Shu on 2019/9/19.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 105;
int dp[maxn][maxn];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            if (t == 0) continue;
            dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
        }
    }

    // 结果并不是 dp[n][m]，而是 dp 数组中的最大值
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d", ans);
    return 0;
}
