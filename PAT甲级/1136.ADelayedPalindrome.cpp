//
// Created by Yiheng Shu on 2019/9/4.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool firstline = true;

void nextline() {
    if (firstline)firstline = false;
    else cout << endl;
}

bool isPalindrome(const string &str) {
    if (str.size() <= 1) return true;
    const int size = str.size();
    for (int i = 0; i < size / 2; i++) {
        if (str[i] != str[size - 1 - i]) return false;
    }
    return true;
}

string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string res;
    int carry = 0;
    // 从低位开始相加
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        int t = carry;
        if (i < a.size()) t += a[i] - '0';
        if (i < b.size()) t += b[i] - '0';
        res.push_back(t % 10 + '0');
        carry = t / 10;
    }
    if (carry) {
        res.push_back(carry + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

string iterate(const string &str) {
    string s(str);
    reverse(s.begin(), s.end());
    string sum = add(str, s);
    nextline();
    cout << str << " + " << s << " = " << sum;
    return sum;
}

int main() {
    string str;
    cin >> str;
    for (int it = 0; it < 10; it++) {
        if (isPalindrome(str)) {
            nextline();
            cout << str << " is a palindromic number.";
            return 0;
        }
        str = iterate(str);
    }
    nextline();
    cout << "Not found in 10 iterations.";
    return 0;
}