#include <iostream>
using namespace std;
#define MAXN 105
int n;
int a[MAXN];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // 熟记冒泡排序
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int t = a[j];
        a[j] = a[j + 1];
        a[j + 1] = t;
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  return 0;
}
