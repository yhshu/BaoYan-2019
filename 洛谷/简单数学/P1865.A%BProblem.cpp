//
// Created by Yiheng Shu on 2019/9/15.
//

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, m;
int l, r;

const int maxm = 1000010;
bool prime[maxm];
int sum[maxm];


int main() {
    cin >> n >> m;

    for (int i = 2; i < maxm; i++) prime[i] = true;
    prime[1] = prime[0] = false;
    for (int i = 2; i <= sqrt(m + 0.5); i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= m; j += i) {
            prime[j] = false;
        }
    }
    for (int i = 1; i <= m; i++) {
        sum[i] = sum[i - 1];
        if (prime[i])
            sum[i]++;
    }

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        if (l > r) swap(l, r);
        if (l < 1 || r > m) printf("Crossing the line\n");
        else printf("%d\n", sum[r] - sum[l - 1]);
    }

    return 0;
}