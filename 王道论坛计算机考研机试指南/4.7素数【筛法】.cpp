#include <cstring>
#include <iostream>
#define MAXN 10005
using namespace std;
int prime[MAXN]; // 保存筛得的素数
int primeSize;
bool mark[MAXN]; // 非素数 true，素数 false

void init() {                        // 素数筛法
  memset(mark, false, sizeof(mark)); // #include <cstring>
  primeSize = 0;
  for (int i = 2; i <= MAXN; i++) {
    if (mark[i])
      continue;
    prime[primeSize++] = i;
    for (int j = i * i; j <= MAXN; j += i) {
      mark[j] = true;
    }
  }
}
int main() {
  init();
  int n;
  while (cin >> n) {
    bool hasOut = false;
    for (int i = 0; i < primeSize; i++) {
      if (prime[i] < n && prime[i] % 10 == 1) {
        if (hasOut == false) {
          hasOut = true;
          cout << prime[i];
        } else
          cout << " " << prime[i];
      }
    }
    if (hasOut == false)
      cout << -1 << endl;
    else
      cout << endl;
    return 0;
  }
}
