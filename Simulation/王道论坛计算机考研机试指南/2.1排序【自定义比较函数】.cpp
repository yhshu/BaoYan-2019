#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 105

bool cmp(int x, int y) { return x > y; } // 降序排列

int n;
int a[MAXN];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n, cmp);

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  return 0;
}
