//
// Created by syh on 19-3-18.
//

/*
 * 输入只有一行，包含两个整数a,b，要求输出[a,b]内所有的回文数，a,b<10^6
 */

#include <iostream>
#include <sstream>

using namespace std;

bool check(int x) {
    stringstream ss;
    string num;
    ss << x;
    ss >> num;
    int i = 0, j = num.size() - 1;
    while (i < j) {
        if (num[i++] != num[j--])
            return false;
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b)swap(a, b);

    for (int i = a; i <= b; i++) {
        if (check(i))
            cout << i << endl;
    }
}