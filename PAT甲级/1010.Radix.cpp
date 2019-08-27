//
// Created by Yiheng Shu on 2019/8/27.
//

/*
Sample Input 1:

6 110 1 10
Sample Output 1:

2
Sample Input 2:

1 ab 1 2
Sample Output 2:

Impossible

 */

// 进制转换题的思路：十进制为中介
// 因为测试点7卡时间，需要使用二分搜索

#include <iostream>
#include <algorithm>

using namespace std;

string n1, n2;
int tag;
long long radix;

void input() {
    cin >> n1 >> n2;
    cin >> tag >> radix;
}

/**
 * 将数字转换为十进制
 * @param str 某进制数
 * @param rad 数的进制
 * @return 该数的十进制表示F
 */
long long convertToDecimal(string str, long long rad) {
    long long res = 0;
    long long wei = 1;
    for (int i = str.size() - 1; i >= 0; i--) { // 从数字低位开始
        int cur;
        if (!isdigit(str[i])) cur = str[i] - 'a' + 10;
        else cur = str[i] - '0';

        res += wei * cur;
        wei *= rad;
    }
    return res;
}

/**
 * 找到某数可能的最小进制
 * @param str 某进制（2～35）下的一个数
 * @return 可能的最小进制
 */
long long minRad(string str) {
    int maxDigit = -1;
    for (int i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            maxDigit = max(maxDigit, str[i] - 'a' + 10);
        } else {
            maxDigit = max(maxDigit, str[i] - '0');
        }
    }
    return maxDigit + 1;
}

void solve() {
    // 首先将已知进制的数转换为十进制
    long long num = convertToDecimal((tag == 1) ? n1 : n2, radix);

    long long low = minRad((tag == 1) ? n2 : n1);
    long long high = max(low, num);

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long converted = convertToDecimal((tag == 1) ? n2 : n1, mid);
        // 如果使用 long long，必须首先判断溢出
        if (converted < 0 || num < converted) high = mid - 1;
        else if (num > converted) low = mid + 1;
        else {
            cout << mid;
            return;
        }
    }
    cout << "Impossible";
}

int main() {
    input();
    solve();
    return 0;
}
