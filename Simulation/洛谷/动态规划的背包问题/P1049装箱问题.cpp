//
// Created by Yiheng Shu on 2019-08-20.
//

#include <iostream>

using namespace std;

const int maxn = 35;
const int maxv = 20005;
int V;
int n;
int v[maxn];
int dp[maxv];

void input() {
    cin >> V >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = V; j - v[i] >= 0; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
    }
}

void output() {
    cout << V - dp[V];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    input();
    solve();
    output();
    return 0;
}
