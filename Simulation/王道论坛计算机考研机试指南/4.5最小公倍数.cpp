#include <iostream>
using namespace std;

int gcd(int a, int b) { // 最大公约数
  return (b != 0) ? gcd(b, a % b) : a;
}
int main() {
  int a, b;
  while (cin >> a >> b) {
    cout << a * b / gcd(a, b) << endl;
  }
  return 0;
}
