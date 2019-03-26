#include <iostream>

using namespace std;

int gcd(int a, int b) { // 最大公约数
    return (b != 0) ? gcd(b, a % b) : a;
}

int lcm(int a, int b) { // 最小公倍数
    return a * b / gcd(a, b);
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << lcm(a, b) << endl;
    }
    return 0;
}
