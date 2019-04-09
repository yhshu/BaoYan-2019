//
// Created by syh on 19-3-18.
//

/*
 * 输入只有一行，包含两个整数a,b，要求输出[a,b]内所有的回文数，a,b<10^6
 */

#include <bits/stdc++.h>

using namespace std;

int num[10]; // 数组低位存数字低位
bool check(int x) {
    // sprintf 可能略快于 stringstream，但此处使用手动转换，程序性能优势明显
    int len = 0;
    while (x) {
        num[len++] = x % 10;
        x /= 10;
    }
    int i = 0, j = len - 1;
    while (i < j) {
        if (num[i++] != num[j--])
            return false;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);

    for (int i = a; i <= b; i++) {
        if (check(i))
            cout << i << endl;
    }

    return 0;
}
