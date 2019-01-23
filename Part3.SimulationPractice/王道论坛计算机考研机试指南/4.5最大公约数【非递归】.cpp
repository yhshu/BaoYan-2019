#include <iostream>
using namespace std;
int gcd(int a, int b) {
  while (b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int main() {
  int a, b;
  while (cin >> a >> b)
    cout << gcd(a, b) << endl;
  return 0;
}
