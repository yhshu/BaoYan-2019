/*
 * 4152:最佳加法表达式
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，并输出该值。例如，在1234中摆放1个加号，最好的摆法就是12+34,和为36

输入
有不超过15组数据
每组数据两行。第一行是整数m，表示有m个加号要放( 0<=m<=50)
第二行是若干个数字。数字总数n不超过50,且 m <= n-1
输出
对每组数据，输出最小加法表达式的值
样例输入
2
123456
1
123456
4
12345
样例输出
102
579
15
提示
要用到高精度计算，即用数组来存放long long 都装不下的大整数，并用模拟列竖式的办法进行大整数的加法。
来源
Guo Wei
 */

// 参考 https://www.cnblogs.com/SuuT/p/8744529.html

#include <iostream>

using namespace std;

const int maxn = 55;

class BigInteger {
public:
    int d[maxn];
    int len;

    void init() {
        len = 0;
        for (int i = 0; i < maxn; i++)
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
        removeLeadingZeros();
    }

    void removeLeadingZeros() {
        while (len > 1 && !d[len - 1])
            len--;
    }

    bool operator<(const BigInteger &bigInteger) const {
        if (len > bigInteger.len) return false;
        else if (len < bigInteger.len) return true;
        // 从高位比较
        for (int i = len - 1; i >= 0; i--) {
            if (d[i] > bigInteger.d[i])return false;
            if (d[i] < bigInteger.d[i])return true;
        }
        return false; // 相等
    }

    BigInteger operator+(const BigInteger &bigInteger) {
        BigInteger res;
        int carry = 0;
        for (int i = 0; i < max(len, bigInteger.len); i++) {
            int t = carry + d[i] + bigInteger.d[i];
            res.d[res.len++] = t % 10;
            carry = t / 10;
        }
        if (carry) {
            res.d[res.len++] = carry;
        }
        return res;
    }

    BigInteger &operator=(const string &str) {
        init();
        for (int i = str.size() - 1; i >= 0; i--) {
            d[len++] = str[i] - '0';
        }
        removeLeadingZeros();
        return *this;
    }
};

ostream &operator<<(ostream &os, const BigInteger &bigInteger) {
    for (int i = bigInteger.len - 1; i >= 0; i--) {
        os << bigInteger.d[i];
    }
    return os;
}

BigInteger dp[maxn][maxn]; // dp[i][j] 表示前i个数中含有j个加号的最小值
string inf = "";           // 表示无穷大，用于 dp 中求最小值

void dpInit(int len, int n) {
    for (int i = 0; i <= len; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = inf;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    string str;
    for (int i = 1; i < maxn; i++)
        inf += "9";

    while (cin >> n) { // n 个加号
        cin >> str;
        int len = str.length(); // 数字长度

        dpInit(len, n);

        for (int i = 1; i <= len; i++) {
            dp[i][0] = str.substr(0, i);  // 没有加号
            for (int j = 1; j <= n; j++) {
                if (i < j + 1) {          // 非法情况：前i个数最多有i-1个加号
                    dp[i][j] = inf;
                } else {
                    for (int k = j; k <= i - 1; k++) {
                        BigInteger lastNum(str.substr(k, i - k));
                        dp[i][j] = min(dp[i][j], dp[k][j - 1] + lastNum);
                        // 前i个数，包含j个加号的最小加法表达式值
                    }
                }
            }
        }
        cout << dp[len][n] << endl;
    }
}
