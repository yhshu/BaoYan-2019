// 本题保证被减数一定大于减数
// 注意点：
// 1. 字符串转换为整数，需要减去 '0'
// 2. 去除前导 0

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 200; // 大整数不超过 200 位

class BigInteger {
public:
    int d[maxn]; // 存储大整数
    int len; // 大整数位数

    void init() {
        len = 0;
        for(int i = 0; i < maxn; i++)
            d[i] = 0;
    }

    BigInteger() {
        init();
    }

    BigInteger(const string &str) {
        init();
        for(int i = str.size() - 1; i >= 0; i--) {
            this->d[len++] = str[i] - '0'; // 注意是字符串转数字
        }
        removeLeadingZero();
    }

    void removeLeadingZero() {
        // 去除前导 0
        while(len > 1 && d[len - 1] == 0)
            len--;
    }

    BigInteger operator-(const BigInteger& bigInteger) {
        // 减法从低位开始
        BigInteger res;
        int borrow = 0;
        for(int i = 0; i < max(this->len, bigInteger.len); i++) {
            int t = d[i] - borrow - bigInteger.d[i];
            if (t < 0) {
                borrow = 1;
                res.d[res.len++] = t + 10;
            } else {
                res.d[res.len++] = t;
                borrow = 0;
            }
        }
        res.removeLeadingZero();
        return res;
    }
};

ostream& operator<<(ostream &os, BigInteger &bigInteger) {
    for(int i = bigInteger.len - 1; i >= 0; i--) {
        os << bigInteger.d[i];
    }
    return os;
}

int main() {
    string a, b;
    cin >> a >> b;
    BigInteger bigInteger1(a);
    BigInteger bigInteger2(b);
    BigInteger res = bigInteger1 - bigInteger2;
    cout << res;
    return 0;
}