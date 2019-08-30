//
// Created by Yiheng Shu on 2019/8/30.
//

/*
Sample Input:
15 43 71

Sample Output:
#123456
 */

#include <iostream>
#include <algorithm>

using namespace std;

int r, g, b;

void input() {
    cin >> r >> g >> b;
}

string convert(int num) {
    string res;
    while (num) {
        int cur = num % 13;
        if (cur >= 10)res.push_back(cur - 10 + 'A'); // 注意大写字母
        else res.push_back('0' + cur);
        num /= 13;
    }
    if (res.size() == 1) res.push_back('0'); // 得分点
    else if (res.empty()) res = "00";           // 得分点
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    // 转换为 13 进制
    cout << "#" << convert(r) << convert(g) << convert(b);
}

int main() {
    input();
    solve();
    return 0;
}