/*
样例输入：
4

样例输出：
5
*/

#include <iostream>
using namespace std;
long long dp[100]; // 注意数据范围
int main() {
  int N;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i < 100; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  while (cin >> N) {
    cout << dp[N] << endl;
  }
  return 0;
}
