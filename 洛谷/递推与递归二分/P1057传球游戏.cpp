//
// Created by Yiheng Shu on 2019-08-21.
//

#include <iostream>

using namespace std;

int n, m;
int ans;
int dp[35][35];  // dp[i][j] 表示走 i 步到达 j 的方案数

void input() {
    cin >> n >> m;
}

void solve() {
    dp[0][1] = 1;

    for (int i = 1; i <= m; i++) {
        dp[i][1] = dp[i - 1][2] + dp[i - 1][n];
        for (int j = 2; j <= n - 1; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
        dp[i][n] = dp[i - 1][1] + dp[i - 1][n - 1];
    }
}

int main() {
    input();
    solve();
    cout << dp[m][1];
    return 0;
}
