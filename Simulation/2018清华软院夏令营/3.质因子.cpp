//
// Created by syh on 19-4-9.
//

// 2018年清华大学软件学院夏令营 第3题

// 给定N个质数，构成集合S，设集合T为由质因子全部在S中的整数构成的集合，求T中第k小的数，其中1<=N<=100,1<=k<=1e5,输出保证在int的范围之内
// 输入：第一行 N，k
// 第二行 N个质数

// 参考 LeetCode 264. Ugly Number II 复习，但本题的质数数量更多

#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    int t;
    cin >> n >> k;

    vector<int> primes; // 质数集合
    vector<int> dp(k + 1); // dp[i] 是第i个符合条件的数
    vector<int> pointer(n, 0); // 质数的指针

    for (int i = 0; i < n; i++) {
        cin >> t;
        primes.push_back(t);
    }

    sort(primes.begin(), primes.end());
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        // 首先找到下一个符合要求的数，然后向后移动指针
        for (int j = 0; j < n; j++) {
            if (dp[i] == 0)
                dp[i] = dp[pointer[j]] * primes[j];
            else dp[i] = min(dp[i], dp[pointer[j]] * primes[j]);
        }
        cout << "dp[" << i << "]: " << dp[i] << endl;
        for (int j = 0; j < n; j++) {
            if (dp[i] == dp[pointer[j]] * primes[j])
                pointer[j]++;
        }
    }
    cout << dp[k];
    return 0;
}
