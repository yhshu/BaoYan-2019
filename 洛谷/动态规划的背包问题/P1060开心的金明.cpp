//
// Created by Yiheng Shu on 2019-08-19.
//

// 01 背包 模板题

#include <iostream>

#define maxc 30010
#define maxn 30

using namespace std;

int c, n; // capacity, the number of items
int p[maxn], w[maxn]; // prices, weights
long long dp[maxc]; // dp[i]: the max value with remaining capacity = i

void input() {
    cin >> c >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> w[i];
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = c; j >= p[i]; j--) {
            dp[j] = max(dp[j], dp[j - p[i]] + w[i] * p[i]);
            //cout << j << ": " << dp[j] << endl;
        }
    }
}

void debug() {
    for (int i = 1; i <= c; i++) {
        cout << i << ": " << dp[i] << endl;
    }
}

void output() {
    cout << dp[c];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    input();
    solve();
    // debug();
    output();
    return 0;
}