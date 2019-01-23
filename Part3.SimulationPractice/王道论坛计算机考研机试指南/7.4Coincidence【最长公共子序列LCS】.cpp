#include <algorithm>
#include <cstring>
#include <iostream>
#define MAXL 105
using namespace std;
int dp[MAXL][MAXL];
// dp[i][j] 表示 s1 的前 i 个字符和 s2 的前 j 个字符
// 分别组成的两个前缀字符串的最长公共子串长度

int main() {
  char s1[MAXL], s2[MAXL];
  while (cin >> s1 >> s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0; i < len1; i++)
      dp[i][0] = 0;
    for (int j = 0; j < len2; j++)
      dp[0][j] = 0;
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (s1[i - 1] != s2[j - 1]) {
          // 字符数组下标从 0 开始，第 i 个字符位置为 s1[i-1]
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        } else
          dp[i][j] = dp[i - 1][j - 1] + 1;
      }
    }
    cout << dp[len1][len2] << endl;
  }
  return 0;
}
