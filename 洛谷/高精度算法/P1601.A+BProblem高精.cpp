//
// Created by Yiheng Shu on 2019/9/10.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 510;

struct BigInteger {
    int len;
    int d[maxn];

    void init() {
        len = 0;
        for (int i = 0; i < maxn; i++) {
            d[i] = 0;
        }
    }

    BigInteger() {
        init();
    }

    BigInteger(string str) {
        init();
        for (int i = str.size() - 1; i >= 0; i--) {
            d[len++] = str[i] - '0';
        }
    }

    BigInteger operator+(const BigInteger &b) {
        BigInteger res;
        int carry = 0;
        for (int i = 0; i < max(len, b.len); i++) {
            int t = (carry + d[i] + b.d[i]);
            res.d[res.len++] = t % 10;
            carry = t / 10;
        }
        if (carry) {
            res.d[res.len++] = carry;
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string a, b;
    cin >> a >> b;
    BigInteger num1(a);
    BigInteger num2(b);

    BigInteger num3 = num1 + num2;
    for (int i = num3.len - 1; i >= 0; i--) {
        printf("%d", num3.d[i]);
    }
    return 0;
}