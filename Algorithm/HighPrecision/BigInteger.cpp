//
// Created by Yiheng Shu on 2019/5/25.
//


// 本程序用于实现 BigInteger 类中的方法

#include "BigInteger.h"
#include <iostream>

using namespace std;

void BigInteger::init() {
    // fill_n (d, sizeof(d), 0);
    // fill_n 需要 #include<algorithm>

    // memset(d, 0, sizeof(d));

    len = 0;    // 注意，如果长整数是0，长度实际是1
    for (int i = 0; i < maxn; i++) {
        d[i] = 0;
    }
}

BigInteger::BigInteger() {
    init();
}

BigInteger::BigInteger(int num) {
    init();
    while (num) {
        int t = num % 10;
        d[len++] = t;
        num /= 10;
    }
}

BigInteger::BigInteger(string str) {
    init();
    for (int i = str.size() - 1; i >= 0; i--) { // 倒序遍历，注意 i 的开始位置是 str.len - 1
        d[len++] = str[i] - '0'; // 注意减去 '0'
    }
    removeLeadingZeros();
}

void BigInteger::removeLeadingZeros() {
    while (len > 1 && d[len - 1] == 0)
        len--;
}

BigInteger BigInteger::operator+(const BigInteger &bigInteger) {
    BigInteger res;
    int carry = 0;  // 用于进位
    // 从低位开始相加
    for (int i = 0; i < max(this->len, bigInteger.len); i++) {
        int t = carry + d[i] + bigInteger.d[i];
        res.d[res.len++] = t % 10;
        carry = t / 10;
    }
    if (carry) {    // 处理最后的进位
        res.d[res.len++] = carry;
    }
    return res;
}

BigInteger BigInteger::operator-(const BigInteger &bigInteger) {
    BigInteger res;
    // 从低位开始相减
    for (int i = 0; i < max(this->len, bigInteger.len); i++) {
        if (d[i] < bigInteger.d[i]) { // 需要借位
            d[i + 1]--;
            d[i] += 10;
        }
        res.d[res.len++] = d[i] - bigInteger.d[i];
    }
    res.removeLeadingZeros();         // 该步骤是必需的
    return res;
}

BigInteger BigInteger::operator*(int num) {
    BigInteger res;
    // 从低位开始相乘
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int t = carry + d[i] * num;
        res.d[res.len++] = t % 10;
        carry = t / 10;
    }
    while (carry) {   // 处理最后的进位
        res.d[res.len++] = carry % 10;
        carry /= 10;
    }
    res.removeLeadingZeros();
    return res;
}

BigInteger BigInteger::operator/(int div) {
    BigInteger res;
    res.len = len;
    int remain = 0; // 余数
    // 从高位开始除法
    for (int i = this->len - 1; i >= 0; i--) {
        remain = remain * 10 + d[i];       // 加上 遗留的余数
        if (remain < div)               // 该位不够除，商填0
            res.d[i] = 0;
        else {                       // 够除
            res.d[i] = remain / div;
            remain %= div;
        }
    }
    res.removeLeadingZeros();        // 该步骤是必需的
    return res;
}

BigInteger div(BigInteger dividend, int divisor, int &remainder) {
    BigInteger res; // 商
    res.len = dividend.len;
    // 从高位开始除法
    for (int i = dividend.len - 1; i >= 0; i--) {
        remainder = remainder * 10 + dividend.d[i];  // 加上 遗留的余数
        if (remainder < divisor)                     // 该位不够除，商填0
            res.d[i] = 0;
        else {                                       // 该位够除
            res.d[i] = remainder / divisor;
            remainder %= divisor;
        }
    }
    res.removeLeadingZeros();                        // 该步骤是必需的
    return res;
}

int BigInteger::compare(const BigInteger &bigInteger) {
    if (len > bigInteger.len) return 1;
    if (len < bigInteger.len) return -1;

    // 从高位开始比较
    for (int i = len - 1; i >= 0; i--) {
        if (d[i] > bigInteger.d[i])
            return 1;
        if (d[i] < bigInteger.d[i])
            return -1;
    }
    return 0; // 两数相等
}

BigInteger BigInteger::operator*(BigInteger bigInteger) {
    BigInteger res("0");
    for (int j = 0; j < bigInteger.len; j++) {
        BigInteger mul = *this * bigInteger.d[j];
        for (int k = 0; k < j; k++) {
            mul = mul * 10;
        }
        res = res + mul;
    }
    return res;
}

BigInteger pow(int a, int n) {
    BigInteger res;
    res.d[res.len++] = 1;
    for (int i = 0; i < n; i++) {
        res = res * a;
    }
    return res;
}

BigInteger factorial(int n) {
    // 从小乘到大，相比于从大乘到小，时间更短
    BigInteger res("1");
    for (int i = 1; i <= n; i++)
        res = res * i;
    return res;
}

ostream &operator<<(ostream &os, const BigInteger &bigInteger) {
    for (int i = bigInteger.len - 1; i >= 0; i--) {
        os << bigInteger.d[i];
    }
    return os;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    string str1, str2;
    while (cin >> str1 >> str2) {
        BigInteger bigInteger1(str1);
        BigInteger bigInteger2(str2);
        int int1 = 9999;
        cout << bigInteger1 + bigInteger2 << endl;
        cout << bigInteger1 - bigInteger2 << endl;
        cout << bigInteger1 * int1 << endl;
        cout << bigInteger1 * bigInteger2 << endl;
        cout << bigInteger1 / int1 << endl;
    }
    return 0;
}