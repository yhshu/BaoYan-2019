#include <iostream>
using namespace std;
int main() {
  int x, y, z, n;
  while (cin >> n) {
    for (int x = 0; x <= 100; x++) {
      for (int y = 0; y <= 100 - x; y++) {
        z = 100 - x - y;
        if (3 * n >= 15 * x + 9 * y + z)
          cout << "x=" << x << ",y=" << y << ",z=" << z << endl;
      }
    }
  }
  return 0;
}
