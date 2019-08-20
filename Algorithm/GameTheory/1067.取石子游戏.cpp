//
// Created by Yiheng Shu on 2019/5/24.
//


// 博弈论：威佐夫博弈

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(false);
    int a, b;
    while (cin >> a >> b) {
        if (a < b) {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        int k = a - b;
        a = (int) (k * (1 + sqrt(5)) / 2.0);
        if (a == b)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
