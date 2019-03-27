//
// Created by 舒意恒 on 2019/3/27.
//


// 0: 1  0
// 1: 01  0
// 2: 1001  1
// 3: 01101001  1
// 4: 1001011001101001  3


// 按照题意超出 long long，但在线评测在 long long 之内

#include <iostream>
#include <cmath>

using namespace std;
const int maxn = 1010;
long long dp[maxn];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    dp[2] = 1;
    for (int i = 3; i <= maxn; i++) {
        dp[i] = dp[i - 2] + (long long) pow(2, i - 3);
    }

    int n;
    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}
