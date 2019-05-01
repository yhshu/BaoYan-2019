// 乘方运算即指定循环次数的乘法

#include "stdafx.h"
#include <iostream>

using namespace std;

const int maxn = 200;

class BigInteger {
public:
    int d[maxn];
    int len;

    void init(){
        len = 0;
        for(int i = 0; i < maxn; i++) {
            d[i] = 0;
        }
    }

    BigInteger() {
        init();
    }

    BigInteger operator*(int a) {
        BigInteger res;
        // 从低位开始乘
        int carry = 0;
        for(int i = 0; i < len; i++) {
            int t = d[i] * a + carry;
            res.d[res.len++] = t % 10;
            carry = t / 10;
        }
        while(carry) {
            res.d[res.len++] = carry % 10;
            carry /= 10;
        }
        res.removeLeadingZero();
        return res;
    }

    void removeLeadingZero() {
        while(len > 1 && d[len - 1] == 0) 
            len--;
    }
};

ostream& operator<< (ostream &os, BigInteger& bigInteger) {
    for(int i = bigInteger.len - 1; i >= 0; i--)
        os << bigInteger.d[i];
    return os;
}

BigInteger pow2(int n) {
    BigInteger res;
    res.d[res.len++] = 1;
    for(int i = 0; i < n; i++)
        res = res * 2;
    return res;
}

int main() {
    int n;
    while(cin >> n) {
        BigInteger res = pow2(n);
        cout << res << endl;
    }
    return 0;
}