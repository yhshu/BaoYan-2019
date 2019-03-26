#include <iostream>

#define MOD 1000
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            break;
        int ans = 1;
        while (b != 0) {
            if (b % 2 == 1) {
                ans *= a;
                ans %= MOD;
            }
            b = b >> 1;
            a *= a;
            a %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
