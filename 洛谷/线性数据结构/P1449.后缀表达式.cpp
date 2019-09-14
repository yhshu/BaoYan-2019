#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<int> s;

bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

int isOperator(char ch) {
    if (ch == '+') return 1;
    if (ch == '-') return 2;
    if (ch == '*') return 3;
    if (ch == '/') return 4;
    return 0;
}

int main() {
    char ch;
    int num = 0;
    while (cin >> ch) {
        if (ch == '@') {
            break;
        }
        if (isDigit(ch)) {
            num *= 10;
            num += (ch - '0');
        } else if (ch == '.') {
            s.push(num);
            num = 0;
        } else if (isOperator(ch)) {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();

            if (ch == '+') s.push(op1 + op2);
            else if (ch == '-') s.push(op1 - op2);
            else if (ch == '*') s.push(op1 * op2);
            else if (ch == '/') s.push(op1 / op2);
        }
    }

    printf("%d", s.top());
    return 0;
}