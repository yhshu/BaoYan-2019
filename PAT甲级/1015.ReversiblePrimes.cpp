//
// Created by Yiheng Shu on 2019/8/28.
//

/*
Sample Input:

73 10
23 2
23 10
-2
Sample Output:

Yes
Yes
No
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num + 0.5); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

string toString(int val) {
    stringstream ss;
    ss << val;
    string res;
    ss >> res;
    return res;
}

/**
 * 将十进制数转换为指定进制（小于10），并反转
 * @param decimal 十进制数
 * @param radix 指定进制，2～9
 * @return 反转后的指定进制数
 */
string reverse(int decimal, int radix) {
    string res;
    if (radix == 10) {  // 如果是十进制，直接反转
        res = toString(decimal);
        reverse(res.begin(), res.end());
        return res;
    }
    while (decimal) {
        res.push_back(decimal % radix + '0');
        decimal /= radix;
    }
    return res;
}

/**
 * 将指定进制数转换为十进制数
 * @param str
 * @param radix
 * @return
 */
int convert(string str, int radix) {
    int wei = 1;
    int res = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        res = res + (str[i] - '0') * wei;
        wei = wei * radix;
    }
    return res;
}

int main() {
    int n, d;
    bool first = true;
    while (cin >> n) {
        if (n < 0) break;
        cin >> d;
        if (first) first = false; else cout << "\n";
        if (isPrime(convert(reverse(n, d), d)) && isPrime(n)) cout << "Yes";
        else cout << "No";
    }
    return 0;
}
