//
// Created by Yiheng Shu on 19-3-27.
//

// 本题是简单的完全背包问题
// 但数据范围超出 long long 几倍

// 求使用不限数目的 1～k 美元凑出 primeNum 美元的方案数

#include <iostream>

using namespace std;

const int minSum = 1005;
long long dp[minSum][41]; // dp[i] 表示 1～k 凑出 i 的方案数
// dp第二维度存储每一位数
int n, k;

int main() {
    while (cin >> n >> k) {
        for (int i = 0; i < minSum; i++)
            for (int j = 0; j < 41; j++)
                dp[i][j] = 0;
        dp[0][1] = 1; // 凑出0有1种方法
        for (int i = 1; i <= k; i++) { // 物品i的代价是i
            for (int j = i; j <= n; j++) { // 容量
                // dp[j] += dp[j - i] 累加方案数
                // 但在第二维要展开处理每一位
                for (int z = 1; z < 40; z++) {
                    dp[j][z] = dp[j][z] + dp[j - i][z];
                    if (dp[j][z] > 9) { // 进位
                        dp[j][z + 1] += dp[j][z] / 10;
                        dp[j][z] %= 10;
                    }
                }
            }
        }

        int maxBit = 40;
        while (dp[n][maxBit] == 0)
            maxBit--;

        for (int i = maxBit; i >= 1; i--)
            cout << dp[n][i];
        cout << "\n";
    }
    return 0;
}