//
// Created by Yiheng Shu on 2019/5/23.
//

/*
 * 9265:取数游戏
查看 提交 统计 提问
总时间限制: 10000ms 单个测试点时间限制: 1000ms 内存限制: 131072kB
描述
我们来玩一个游戏：自然数1到N，按顺序列成一排，你可以从中取走任意个数，但是相邻的两个不可以同时被取走。如果你能算出一共有多少种取法，那么你会被天神Lijiganjun奖励。

输入
仅包含一个数n（1< n < 50）。

输出
仅包含一个数———你的答案。

样例输入
5
样例输出
13
来源
递推五十题
 */

// 注意，本题类似于斐波那契数列，但不完全相同
// dp[1] = 2, dp[2] = 3

#include <iostream>

using namespace std;
const int maxn = 60;
long long dp[maxn]; // 注意答案的范围

int main() {
    int n;
    cin >> n;

    dp[1] = 2;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // dp[i - 1] 对应于本步不取数，dp[i - 2] 对应于本步取数
    }
    cout << dp[n] << endl;
    return 0;
}
