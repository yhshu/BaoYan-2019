#include <iostream>

#define MAXN 25
using namespace std;
long long F[MAXN];

int main() {
    int n;
    F[1] = 0;
    F[2] = 1;
    for (int i = 3; i < MAXN; i++) {
        F[i] = (i - 1) * (F[i - 1] + F[i - 2]);
    }
    while (cin >> n) {
        cout << F[n] << endl;
    }
    return 0;
}
