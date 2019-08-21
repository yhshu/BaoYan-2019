//
// Created by Yiheng Shu on 2019-08-21.
//

#include <iostream>

using namespace std;

int n, k;
const int maxn = 100010;
const int mod = 100003;
int dp[maxn];

void input() {
    cin >> n >> k;
}

void solve() {
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0)
                dp[i] = (dp[i - j] + dp[i]) % mod;
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