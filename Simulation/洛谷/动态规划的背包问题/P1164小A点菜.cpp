//
// Created by Yiheng Shu on 2019-08-20.
//

#include <iostream>

#define maxn 105
using namespace std;

int n;          // 菜品数量
int m;          // 拥有的金额
int nums[maxn]; // 各菜品价格
int dp[maxn];   // dp[i] 是花光 i 元的方案数

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
}

void solve() {
    dp[0] = 1;  // 花0元点0个菜 是1种方案
    if (nums[0] <= m) {
        dp[nums[0]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j - nums[i] >= 0; j--) {
            dp[j] = dp[j] + dp[j - nums[i]];
        }
    }
}

void output() {
    cout << dp[m];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    input();
    solve();
    output();
    return 0;
}