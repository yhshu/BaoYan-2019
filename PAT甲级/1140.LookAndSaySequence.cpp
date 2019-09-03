//
// Created by Yiheng Shu on 2019/9/3.
//

#include <iostream>

using namespace std;

int main() {
    string d;
    int n;
    cin >> d >> n;

    for (int cnt = 1; cnt < n; cnt++) {
        string next;;
        if (d.size() == 1) {
            d += "1";
            continue;
        }
        int len = 1;
        for (int idx = 1; idx < d.size(); idx++) {
            if (d[idx - 1] == d[idx]) {
                len++;
            } else {
                next += d[idx - 1] + to_string(len);
                len = 1;
            }
            if (idx == d.size() - 1) {
                next += d[idx] + to_string(len);
            }
        }
        d = next;
    }
    cout << d;

    return 0;
}