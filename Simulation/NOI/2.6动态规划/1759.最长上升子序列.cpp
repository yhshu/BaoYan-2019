/*
1759:最长上升子序列
查看 提交 统计 提问
总时间限制: 2000ms 内存限制: 65536kB
描述
一个数的序列bi，当b1 < b2 < ... < bS的时候，我们称这个序列是上升的。对于给定的一个序列(a1, a2, ..., aN)，我们可以得到一些上升的子序列(ai1, ai2, ..., aiK)，这里1 <= i1 < i2 < ... < iK <= N。比如，对于序列(1, 7, 3, 5, 9, 4, 8)，有它的一些上升子序列，如(1, 7), (3, 4, 8)等等。这些子序列中最长的长度是4，比如子序列(1, 3, 5, 8).

你的任务，就是对于给定的序列，求出最长上升子序列的长度。
输入
输入的第一行是序列的长度N (1 <= N <= 1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000。
输出
最长上升子序列的长度。
样例输入
7
1 7 3 5 9 4 8
样例输出
4
*/

#include <iostream>

using namespace std;

const int maxn = 1010;
int nums[maxn];
int n;
int dp[maxn]; // dp[i] 表示 nums[0...i] 的最长上升子序列长度

int lis() {
    int ans = 1; // 注意！ans 的初始值应是 1；考虑输入是一个下降序列或所有数字相同的情况
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
                // cout << nums[j] << " " << nums[i] << " "<<dp[i] << endl;
            }
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < maxn; i++)
        dp[i] = 1;

    cout << lis() << endl;

    return 0;
}
