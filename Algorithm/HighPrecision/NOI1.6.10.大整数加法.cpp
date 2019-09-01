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


// 本题注意点：
// 1. 字符串的高位是大数的低位，注意字符串的循环变量的范围
// 2. 输入的数字可能有前导0，如果该数字就是0，要保留一位0

#include "stdafx.h"
#include <iostream>
#include <cstring>

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
        for (int i = str.size() - 1; i >= 0; i--) { // 注意循环变量的范围
            this->d[len++] = str[i] - '0';
        }
        while (len > 1 && d[len - 1] == 0) {
            len--;
        }
    }

    BigInteger operator+(const BigInteger &bigInteger) {
        BigInteger res;
        int carry = 0;
        // 从大数低位开始相加
        for (int i = 0; i < max(this->len, bigInteger.len); i++) { // 注意循环变量的范围
            int t = d[i] + bigInteger.d[i] + carry;
            res.d[res.len++] = t % 10;
            carry = t / 10;
        }
        if (carry) // 处理最后的进位
            res.d[res.len++] = carry;
        return res;
    }
};

ostream &operator<<(ostream &os, const BigInteger &bigInteger) {
    for (int i = bigInteger.len - 1; i >= 0; i--) {
        os << bigInteger.d[i];
    }
    return os;
}

int main() {
    string a, b;
    cin >> a >> b;

    BigInteger bigInt1(a);
    BigInteger bigInt2(b);
    BigInteger res = bigInt1 + bigInt2;
    cout << res;

    return 0;
}
