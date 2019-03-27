/*
样例输入：
8
300 207 155 300 299 170 158 65
样例输出：
6
来源：
*/

// 本题的问题是最长非递增子序列
#include <iostream>

#define MAXN 26
using namespace std;
int list[MAXN]; // 原序列
int dp[MAXN]; // dp[i]是前i个数字中的最长非递增子序列的长度
int main() {
    // 输入
    int n, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    // 暴力解法
    // 注意，dp的索引范围比原数组大小多1
    for (int i = 1; i <= n; i++) {
        int tmax = 1;
        for (int j = 1; j < i; j++) {
            if (list[j] >= list[i])
                tmax = max(tmax, dp[j] + 1);
        }
        dp[i] = tmax;
    }

    // 通过dp数组计算答案
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
