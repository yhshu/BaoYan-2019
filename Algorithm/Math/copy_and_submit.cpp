//
// Created by Yiheng Shu on 19-4-24.
//

#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

const long long mod = 998244353LL;

map<long long, map<long long, long long> > gcdmp;
map<long long, map<long long, long long> > ansmp;

// 快速乘法
long long mul(long long a, long long b) {
    long long res = 0;
    while (b) {
        if (b & 1) {
            res += a;
            res %= mod;
        }
        b >>= 1;
        a <<= 1;
        a %= mod;
    }
    return res;
}

long long solve(long long n, long long m) {
    if (n > m)
        return solve(m, n);
    if (ansmp[n][m] != 0)
        return ansmp[n][m];
    long long ans = 0;

    for (long long i = 1; i <= n; ++i) {
        for (long long j = i+1 ; j <= n; ++j) {
            if (gcdmp[i][j] == 1) {
//                printf("i: %d, j: %d, ", i, j);
                ans = (ans + mul(i, j)) % mod;
            } else {
                gcdmp[i][j] = __gcd(i, j);
                if (gcdmp[i][j] == 1) {
//                    printf("i: %d, j: %d\n", i, j);
                    ans = (ans + mul(i, j)) % mod;
                }
            }
//            ansmp[i][j] = ans;
//            printf("ans: %d\n", ans);
        }
    }
    ans = (mul(ans, 2)) % mod;
    ans = (ans + 1) % mod;
//    printf("ans: %d\n", ans);
    for (long long i = 1; i <= n; ++i) {
        for (long long j = n + 1; j <= m; ++j) {
            if (gcdmp[i][j] == 1) {
//                printf("i: %d, j: %d\n", i, j);
                ans = (ans + mul(i, j)) % mod;
            } else {
                gcdmp[i][j] = __gcd(i, j);
                if (gcdmp[i][j] == 1) {
//                    printf("i: %d, j: %d\n", i, j);
                    ans = (ans + mul(i, j)) % mod;
                }
            }
//            ansmp[i][j] = ans;
//            printf("ans: %d\n", ans);
        }
    }
    long long ret = (mul(ans, 8)) % mod;
    ansmp[n][m] = ret;
    return ret;
}

int main() {
    int T;
    long long n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", solve(n, m));
    }
    return 0;
}
