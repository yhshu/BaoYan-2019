//
// Created by Yiheng Shu on 2019/9/11.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int b;

const int maxn = 2010;

int charToInt(char ch) {
    if ('A' <= ch && ch <= 'Z') return ch - 'A' + 10;
    return ch - '0';
}

struct BigInteger {
    int len;
    char d[maxn];

    void init() {
        len = 0;
        for (int i = 0; i < maxn; i++) d[i] = '0';
    }

    BigInteger() {
        init();
    }

    BigInteger(string str) {
        init();
        for (int i = str.size() - 1; i >= 0; i--) {
            d[len++] = str[i];
        }
    }

    BigInteger operator+(const BigInteger &bigInteger) {
        BigInteger res;
        int carry = 0;
        for (int i = 0; i < max(len, bigInteger.len); i++) {
            int t = (carry + charToInt(d[i]) + charToInt(bigInteger.d[i]));
            carry = t / b;
            if (t % b < 10) {
                res.d[res.len++] = '0' + (t % b);
            } else {
                res.d[res.len++] = (t % b) - 10 + 'A';
            }
        }
        if (carry) {
            if (carry % b < 10) {
                res.d[res.len++] = '0' + (carry % b);
            } else {
                res.d[res.len++] = (carry % b) - 10 + 'A';
            }
        }
        return res;
    }
};

int main() {

    cin >> b;
    string str1, str2;
    cin >> str1 >> str2;

    BigInteger bigInteger1(str1);
    BigInteger bigInteger2(str2);
    BigInteger res = bigInteger1 + bigInteger2;
    for (int i = res.len - 1; i >= 0; i--) {
        printf("%c", res.d[i]);
    }

    return 0;
}