//
// Created by Yiheng Shu on 2019/8/27.
//

/*
Sample Input:

12345
Sample Output:

one five
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string str;     // 最长长度 100 位
int sum;
stack<int> digitStack;
// 无需使用高精度，每位数字最大是 9，100 位数字的和最大是 900
vector<string> numberMap;

void input() {
    cin >> str;
    numberMap.push_back("zero");
    numberMap.push_back("one");
    numberMap.push_back("two");
    numberMap.push_back("three");
    numberMap.push_back("four");
    numberMap.push_back("five");
    numberMap.push_back("six");
    numberMap.push_back("seven");
    numberMap.push_back("eight");
    numberMap.push_back("nine");
}

void solve() {
    for (int i = 0; i < str.size(); i++) {
        sum += (str[i] - '0');
    }
    if (sum == 0)
        digitStack.push(0);
    while (sum) {
        digitStack.push(sum % 10);
        sum /= 10;
    }
}

void output() {
    bool first = true;
    while (!digitStack.empty()) {
        int digit = digitStack.top();
        digitStack.pop();

        if (first) {
            first = false;
            cout << numberMap[digit];
        } else {
            cout << " " << numberMap[digit];
        }
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}