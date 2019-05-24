/*
23:区间内的真素数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
找出正整数 M 和 N 之间（N 不小于 M）的所有真素数。

真素数的定义：如果一个正整数 P 为素数，且其反序也为素数，那么 P 就为真素数。
例如，11，13 均为真素数，因为11的反序还是为11，13 的反序为 31 也为素数。

输入
输入两个数 M 和 N，空格间隔，1 <= M <= N <= 100000。
输出
按从小到大输出 M 和 N 之间（包括 M 和 N ）的真素数，逗号间隔。如果之间没有真素数，则输出 No。
样例输入
10 35
样例输出
11,13,17,31
来源
元培-From Whf
*/

#include <iostream>
#include <cmath>

using namespace std;

int M, N;

int reverse(int x) {
    int res = 0;
    while (x) {
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

bool checkPrime(int x) {
    int m = (int) sqrt(x + 0.5);
    for (int i = 2; i <= m; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool checkRealPrime(int x) {
    return checkPrime(x) && checkPrime(reverse(x));
}

int main() {
    cin >> M >> N;
    bool first = true;
    bool empty = true;
    for (int i = M; i <= N; i++) {
        if (checkRealPrime(i)) {
            if (!first)
                cout << ",";
            cout << i;
            first = false;
            empty = false;
        }
    }
    if (empty)
        cout << "No";
    return 0;
}
