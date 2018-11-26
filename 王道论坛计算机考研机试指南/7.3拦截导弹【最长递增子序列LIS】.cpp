/*
样例输入：
8
300 207 155 300 299 170 158 65
样例输出：
6
来源：
*/

// 本题并非是最长递增子序列，而是最长非递增子序列
#include <iostream>
#define MAXN 26
using namespace std;
int list[MAXN]; // 原序列
int dp[MAXN]; // 保存以第i个数字结尾的最长非递增子序列的长度
int main() {
  int n, ans = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> list[i];
  }

  for (int i = 1; i <= n; i++) {
    int tmax = 1;
    for (int j = 1; j < i; j++) {
      if (list[j] >= list[i])
        tmax = max(tmax, dp[j] + 1);
    }
    dp[i] = tmax;
  }

  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
