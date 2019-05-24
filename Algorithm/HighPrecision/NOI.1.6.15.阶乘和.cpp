#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;

const int maxn = 200;

class BigInteger {
public:
    int d[maxn];
    int len;

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
        for (int i = str.size() - 1; i >= 0; i--) {
            d[len++] = str[i] - '0';
        }
        removeLeadingZero();
    }

    void removeLeadingZero() {
        while (len > 1 && d[len - 1] == 0) len--;
    }

    BigInteger operator+(const BigInteger &bigInteger) {
        int newLen = 0;
        int carry = 0;
        for(int i = 0; i < max(len, bigInteger.len); i++) {
            int t = carry + d[i] + bigInteger.d[i];
            d[newLen++] = t % 10;
            carry = t / 10;
        }
        if(carry) {
            d[newLen++] = carry;
        }
        len = newLen;
        removeLeadingZero();
        return *this;
    }

    BigInteger operator*(int a) {
        int carry = 0;
        int newLen = 0;
        for (int i = 0; i < len; i++) {
            int t = carry + d[i] * a;
            d[newLen++] = t % 10;
            carry = t / 10;
        }
        while (carry) {
            d[newLen++] = carry % 10;
            carry /= 10;
        }
        len = newLen;
        removeLeadingZero();
        return *this;
    }
};

ostream &operator<<(ostream &os, const BigInteger &bigInteger) {
    for (int i = bigInteger.len - 1; i >= 0; i--) {
        cout << bigInteger.d[i];
    }
    return os;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n <= 1) {
        cout << 1 << endl; // 0! 是 1
        return 0;
    }
    stringstream ss;
    ss << n;
    string str;
    ss >> str;
    BigInteger bigInteger("1");
    BigInteger res("0");
    for (int i = 1; i <= n; i++) {
        bigInteger = bigInteger * i;
        // cout << bigInteger << endl;
        res = res + bigInteger;
        // cout << res << endl;
    }
    cout << res << endl;
    return 0;
}
