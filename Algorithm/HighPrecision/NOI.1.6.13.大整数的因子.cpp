// 注意点：仔细读题，可能没有符合要求的整数，输出none

#include "stdafx.h"

#include <iostream>

using namespace std;

const int maxn = 35;

class BigInteger {
public:
    int d[maxn];
    int len;

    void init() {
        len = 0;
        for(int i = 0; i < maxn; i++) {
            d[i] = 0;
        }
    }

    BigInteger(const string& str) {
        init();
        for(int i = str.size() - 1; i >= 0; i--) {
            d[len++] = str[i] - '0';
        }
        removeLeadingZero();
    }

    void removeLeadingZero() {
        while(len > 1 && d[len - 1] == 0) len--;
    }

    int operator%(int a) {
        int r = 0; // 余数
        // 从高位开始除
        for(int i = len - 1; i >= 0; i--) {
            r = r * 10 + d[i];
            if(r >= a) { // 该位够除
                r = r % a;
            }
        }
        return r;
    }
};

int main() {
    string str;
    cin >> str;
    BigInteger c(str);
    bool none = true;
    for(int k = 2; k <= 9; k++) {
        if(c % k == 0) {
            cout << k << " ";
            none = false;
        }
    }
    if(none)
        cout << "none"; // 可能没有符合要求的整数，输出none
    return 0;
}
