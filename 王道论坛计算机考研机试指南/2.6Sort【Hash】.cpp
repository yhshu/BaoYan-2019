#include <cstring>
#include <iostream>
#define OFFSET 500000

using namespace std;

int Hash[2 * OFFSET + 10];
int main() {
  int n, m;
  int x;
  while (cin >> n >> m) {
    memset(Hash, 0, sizeof(Hash)); // #include<cstring>
    for (int i = 1; i <= n; i++) {
      cin >> x;
      Hash[OFFSET + x] = 1;
    }
    for (int i = OFFSET; i >= -OFFSET; i--) {
      if (Hash[i + OFFSET] == 1)
        cout << i;
      m--;
      if (m)
        cout << " ";
      else {
        cout << endl;
        break;
      }
    }
  }
}
