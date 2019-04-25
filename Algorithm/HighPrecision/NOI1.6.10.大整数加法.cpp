/*
10:大整数加法
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
求两个不超过200位的非负整数的和。

输入
有两行，每行是一个不超过200位的非负整数，可能有多余的前导0。
输出
一行，即相加后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
样例输入
22222222222222222222
33333333333333333333
样例输出
55555555555555555555
来源
程序设计实习2007
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int maxlen = 205;

class BigInteger {
public:
    int len;
    int d[maxlen]; // 数组低位存储大数低位

    // 初始化
    void init() {
        len = 0;
        memset(d, 0, sizeof(d));
    }
    
    // 构造方法
    BigInteger() {
        init();
    }

    BigInteger(const string &str) { // 字符串的低位是数字的高位
        init();
        for(int i = str.size(); i >= 0; i--) {
            this->d[len++] = str[i];
        }
    }

    BigInteger operator+(const BigInteger &bigInteger) {
        BigInteger res;
        int carry = 0;
        // 从大数低位开始相加
        for(int i = 0; i < max(this->len, bigInteger.len); i++) {
            int t = d[i] + bigInteger.d[i] + carry;
            res.d[res.len++] = t % 10;
            carry = t / 10;
        }
        if(carry)
            res.d[res.len++] = carry;
        return res;
    }
};

ostream &operator<<(ostream &os, const BigInteger &bigInteger) {
    for(int i = bigInteger.len - 1; i >= 0; i--) {
        os << bigInteger.d[i];
    }
    return os;
}

int main() {
    string a, b;
    cin >> a >> b;

    BigInteger bigInt1(a);
    BigInteger bigInt2(b);
    BigInteger res = a + b;
    cout << res;

    return 0;
}
