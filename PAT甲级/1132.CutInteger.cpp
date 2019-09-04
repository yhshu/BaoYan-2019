//
// Created by Yiheng Shu on 2019/9/4.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool firstline = true;

void nextline() {
    if (firstline) firstline = false;
    else cout << endl;
}

bool judge(long long num) {
    string str = to_string(num);
    const int size = str.size();
    long long mod = pow(10, size / 2);
    long long num2 = num % mod;
    long long num1 = (num - num2) / mod;
    if (!num1 || !num2) return false;  // 给分点，避免浮点错误
    return num % (num1 * num2) == 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        nextline();
        if (judge(num)) cout << "Yes";
        else cout << "No";
    }
    return 0;
}
