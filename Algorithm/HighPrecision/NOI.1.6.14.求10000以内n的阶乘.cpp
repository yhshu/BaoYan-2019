// 注意点
// 1. 大数数组的长度根据题目要求确定大小，数组不能太长
// 2. 如果使用 new 创建数组，不用自己手动编写析构函数
// 3. 注意可能超时，减少计算时间的方法：从小乘到大，in-place的方式进行乘法计算
// 4. 快速乘法不适用于加速大整数乘法
// 5. 注意 0! = 1

//#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;

const int maxn = 36000;

class BigInteger {
public:
    int *d;
    int len;

    void init() {
        d = new int[maxn];
        len = 0;
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
    for (int i = 1; i <= n; i++) {
        bigInteger = bigInteger * i;
    }
    cout << bigInteger << endl;
//    cout << bigInteger.len << endl;
    return 0;
}
