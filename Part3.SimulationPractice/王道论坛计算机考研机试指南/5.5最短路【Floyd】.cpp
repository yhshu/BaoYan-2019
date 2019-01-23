/*
样例输入；
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0
样例输出：
3
2

*/
#include <iostream>
using namespace std;
#define MAXN 105
int ans[MAXN][MAXN];
int main() {
  int n, m;
  while (cin >> n >> m && n && m) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ans[i][j] = -1;
      }
      ans[i][i] = 0;
    }
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      ans[a][b] = ans[b][a] = c;
    }
    for (int k = 1; k <= n; k++) { // Floyd 算法
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (ans[i][k] == -1 || ans[k][j] == -1)
            continue;
          if (ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j]) {
            ans[i][j] = ans[i][k] + ans[k][j];
          }
        }
      }
    }
    cout << ans[1][n] << endl;
  }
  return 0;
}
