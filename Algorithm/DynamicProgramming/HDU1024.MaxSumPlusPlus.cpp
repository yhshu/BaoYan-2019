//
// Created by Yiheng Shu on 2019/5/13.
//


/*
 * Max Sum Plus Plus HDU - 1024
Now I think you have got an AC in Ignatius.L's "Max Sum" problem. To be a brave ACMer, we always challenge ourselves to more difficult problems. Now you are faced with a more difficult problem.

Given a consecutive number sequence S 1, S 2, S 3, S 4 ... S x, ... S n (1 ≤ x ≤ n ≤ 1,000,000, -32768 ≤ S x ≤ 32767). We define a function sum(i, j) = S i + ... + S j (1 ≤ i ≤ j ≤ n).

Now given an integer m (m > 0), your task is to find m pairs of i and j which make sum(i 1, j 1) + sum(i 2, j 2) + sum(i 3, j 3) + ... + sum(i m, j m) maximal (i x ≤ i y ≤ j x or i x ≤ j y ≤ j x is not allowed).

But I`m lazy, I don't want to write a special-judge module, so you don't have to output m pairs of i and j, just output the maximal summation of sum(i x, j x)(1 ≤ x ≤ m) instead. ^_^
Input
Each test case will begin with two integers m and n, followed by n integers S 1, S 2, S 3 ... S n.
Process to the len of file.
Output
Output the maximal summation described above in one line.
Sample Input
1 3 1 2 3
2 6 -1 4 -2 3 -2 3
Sample Output
6
8

Hint
Huge input, scanf and dynamic programming is recommended.
 */

// dp[i][j] 表示前j个数分为i组的最大和，在实现中降维
// dp[i][j] = max(dp[i][j - 1], dp[i][j - 1] + nums[j], dp[i - 1][k] + nums[j] (0 < k < j))
// 对应的三种情况分别是：1)不计算当前数字，2)将当前数字放入最后一段区间，3)以当前数字开始作为一段新的区间
// 注意，答案可能是负数，因此 dp[0] 和 ans 初始化为 -inf

#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100010;
const int inf = 0x3f3f3f3f;
int nums[maxn];
int preMax[maxn];
int dp[maxn];
int ans;

int main() {
    int m, n;
    while (~scanf("%d%d", &m, &n)) {
        ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        for (int i = 0; i < maxn; i++) {
            dp[i] = 0;
            preMax[i] = 0;
        }
        dp[0] = -inf;

        for (int i = 1; i <= m; i++) {
            ans = -inf;  // 答案可能是负数
            for (int j = i; j <= n; j++) {
                dp[j] = max(dp[j - 1] + nums[j - 1], preMax[j - 1] + nums[j - 1]);
                // 第一项是将当前数字放入最后一段区间的情况
                // 第二项是以当前数字开始作为新区间的情况
                preMax[j - 1] = ans;  // preMax 的更新方式确保 dp 数组可以降维
                ans = max(ans, dp[j]);  // ans 总是取最大值，因而隐含考虑了不计算当前数字的情况
            }
        }
        cout << ans << endl;
    }
    return 0;
}
