//
// Created by Yiheng Shu on 2019/9/9.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int range, nQuery;
const int maxn = 10000010;
bool isPrime[maxn];

int main() {
    cin >> range >> nQuery;
    fill(isPrime, isPrime + maxn, true);
    isPrime[0] = isPrime[1] = false;

    int m = (int) sqrt(range + 0.5);
    for (int i = 2; i <= m; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= range; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 0; i < nQuery; i++) {
        int t;
        cin >> t;
        if (isPrime[t]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}