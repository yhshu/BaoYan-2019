/*
样例输入：
2
1 3
0
样例输出：
-1
*/
#include <iostream>
using namespace std;
int a[210];
int main() {
  int n, x, res = -1;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> x;
  for (int i = 0; i < n; i++) {
    if (x == a[i])
      res = i;
  }
  cout << res;
  return 0;
}
