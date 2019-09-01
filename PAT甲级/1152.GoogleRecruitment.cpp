//
// Created by Yiheng Shu on 2019/9/1.
//

/*
Sample Input 1:

20 5
23654987725541023819

Sample Output 1:

49877

Sample Input 2:

10 3
2468024680

Sample Output 2:

404
 */

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

int l, k;
string str;
bool solved;

void input() {
    cin >> l >> k;
    if (!l || !k) {
        cout << 404;
        solved = true;
    }
}

int generate(int start, int len) {
    string sub = str.substr(start, len);
    int res = 0;
    int wei = 1;
    for (int i = sub.size() - 1; i >= 0; i--) {
        res += (sub[i] - '0') * wei;
        wei *= 10;
    }
    return res;
}

/**
 * 质数判断
 * @param num 小于 10 位的整数
 * @return 质数true，非质数false
 */
bool judge(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num + 0.5); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void output(int n) {
    stringstream ss;
    ss << n;
    string str;
    ss >> str;
    while (str.size() < k) {
        str = "0" + str;
    }
    cout << str;
}

void solve() {
    cin >> str;
    for (int i = 0; i + k - 1 < str.size(); i++) {
        int g = generate(i, k);
        if (judge(g)) {
            output(g);
            solved = true;
            return;
        }
    }
    if (!solved)
        cout << 404;
}

int main() {
    input();
    solve();
    return 0;
}
