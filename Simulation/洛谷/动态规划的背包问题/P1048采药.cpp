//
// Created by Yiheng Shu on 2019-08-20.
//

// 0-1 背包 模板题

#include <iostream>

using namespace std;

const int maxm = 105;
const int maxt = 1005;
int T, M; // 采药时间，采药数目
int t[maxm];
int v[maxm];
int dp[maxt];

void input() {
    cin >> T >> M;
    for (int i = 0; i < M; i++) {
        cin >> t[i] >> v[i];
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        for (int j = T; j - t[i] >= 0; j--) {
            dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
        }
    }
}

void output() {
    cout << dp[T];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    input();
    solve();
    output();
    return 0;
}