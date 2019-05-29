//
// Created by syh on 19-4-9.
//

/*
2738:实数加法
总时间限制: 1000ms 内存限制: 65536kB
描述
        求两个实数相加的和。

题目中输入输出里出现的浮点数都有如下的形式：
P1P2...Pi.Q1Q2...Qj。对于整数部分，P1P2...Pi是一个非负整数且当整数部分不为0时，P1不等于0；对于小数部分，Qj不等于0。

输入
2行，每行是一个加数。每个加数的长度不超过100。

输出
        一行，即相应的和。输出保证一定是一个小数部分不为0的实数。
样例输入
0.111111111111111111111111111111
0.111111111111111111111111111111
样例输出
0.222222222222222222222222222222
*/


/*
 * 注意点：
 * 1. 即使实数为0，整数部分的长度至少为1
 * 2. 注意数组索引和实际长度的区别
 * 3. 注意进位，以及两数长度的差异
 * 4. 注意初始化，将数组全置为0
 */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;

class BigDecimal {
public:
    int inte[maxn];   // 整数部分
    int deci[maxn];   // 小数部分
    int intLen, deciLen;  // 整数部分长度，小数部分长度

    void init() {
        memset(inte, 0, sizeof(inte));
        memset(deci, 0, sizeof(deci));
        intLen = 1; // 整数部分至少一位
        deciLen = 0;
    }

    BigDecimal() {
        init();
    }

    BigDecimal(const string &str) {
        init();
        int i;
        for (i = 0; i < str.size(); i++) {
            if (str[i] == '.')
                break;
        }
        int i1 = i - 1, i2 = i + 1; // 从小数点向两端遍历
        intLen = deciLen = 0;
        while (i1 >= 0) { // 存储整数部分
            inte[intLen++] = str[i1--] - '0';
        }
        while (i2 < str.size()) {
            deci[deciLen++] = str[i2++] - '0';
        }
    }

    BigDecimal operator+(const BigDecimal &bigDecimal) {
        // 首先小数部分相加，它可能进位到整数部分，然后整数部分相加

        BigDecimal sum; // 两数相加的和
        int carry = 0; // 进位，贯穿小数部分和整数部分的相加
        int t = 0;
        // 从小数最后一位开始相加
        sum.deciLen = max(this->deciLen, bigDecimal.deciLen);
        for (int i = sum.deciLen - 1; i >= 0; i--) {
            t = this->deci[i] + bigDecimal.deci[i];
            sum.deci[i] = (t + carry) % 10;
            carry = (t + carry) / 10;
        }

        // 整数部分相加
        sum.intLen = max(this->intLen, bigDecimal.intLen);
        for (int i = 0; i < sum.intLen; i++) {
            t = this->inte[i] + bigDecimal.inte[i];
            sum.inte[i] = (t + carry) % 10;
            carry = (t + carry) / 10;
        }
        if (carry) {
            sum.inte[sum.intLen++] = carry;
        }
        sum.size(); // 重新计算两部分长度，相加后可能部分数位为0
        return sum;
    }

    string toString() {
        stringstream ss;
        // 整数部分
        for (int i = intLen - 1; i >= 0; i--) {
            ss << inte[i];
        }
        // 小数点
        ss << ".";
        // 小数部分
        for (int i = 0; i < deciLen; i++) {
            ss << deci[i];
        }
        return ss.str();
    }

    /**
     * 重新计算整数部分和小数部分的长度
     */
    void size() {
        while (deciLen > 0) {
            if (!deci[deciLen - 1]) // 小数位 deciLen 为 deci[deciLen - 1]
                deciLen--;
            else break;
        }
        while (intLen > 1) { // 整数部分至少有一位0
            if (!inte[intLen - 1])
                intLen--;
            else break;
        }
    }
};

int main() {
    string a, b;
    cin >> a >> b;
    BigDecimal bd1(a);
    BigDecimal bd2(b);
    BigDecimal bd3 = bd1 + bd2;
    cout << bd3.toString() << endl;
    return 0;
}
