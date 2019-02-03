/* 本题过于简单，没有充分体现 Hash 的概念 */
#include <iostream>
#define MAXN 110
using namespace std;

int main() {
  int n, x;
  while (cin >> n && n) {
    int Hash[MAXN] = {0};
    for (int i = 1; i <= n; i++) {
      cin >> x;
      Hash[x]++;
    }
    cin >> x;
    cout << Hash[x] << endl;
  }
  return 0;
}
